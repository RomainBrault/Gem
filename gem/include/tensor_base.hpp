#ifndef TENSOR_BASE_HPP_INCLUDED
#define TENSOR_BASE_HPP_INCLUDED

#include <ostream>
#include <string>

#include <boost/hana/type.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/reverse.hpp>
#include <boost/hana/back.hpp>
#include <boost/hana/drop_back.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/greater.hpp>
#include <boost/hana/assert.hpp>

#include <cereal/cereal.hpp>
#include <cereal/access.hpp>

#include <gem/type.hpp>
#include <gem/dimensions_tuple.hpp>
#include <gem/cereal/hana_binder.hpp>

namespace gem {

template <typename dtype, long long n_con, long long n_cov,
          GemDimension... dims>
class TensorBase
{

public:
    using type_t = TensorBase;
    using data_t = dtype;

    using dimension_tuple_t = DimensionTuple<false, n_con, n_cov, dims...>;
    using dimension_tuple_common_t = typename dimension_tuple_t::common_t;

    template<typename n_dtype, long long n_n_con, long long n_n_cov,
             GemDimension... n_dims>
    friend class TensorBase;

    friend class cereal::access;

public:
    static constexpr
    boost::hana::type<type_t> type {};

    static constexpr
    boost::hana::type<data_t> data_type {};

    static constexpr
    boost::hana::llong<sizeof...(dims)> order {};

    static constexpr
    boost::hana::llong<n_con> contravariants {};

    static constexpr
    boost::hana::llong<n_cov> covariants {};

    dimension_tuple_t dim;

    static constexpr BOOST_HANA_CONSTANT_CHECK_MSG(
        contravariants + covariants == order,
        "Contravariants and covariants must add up to the order "
        "(number of dimensions)");
    static constexpr BOOST_HANA_CONSTANT_CHECK_MSG(
        0_c <= contravariants,
        "The number of contravariants must be positive");
    static constexpr  BOOST_HANA_CONSTANT_CHECK_MSG(
        0_c <= covariants,
        "The number of covariants must be positive");

public:

    TensorBase(void) = delete;

    constexpr inline TensorBase(const dims&... d) noexcept :
        dim {d...}
    {

    }

    constexpr inline TensorBase(dims&&... d) noexcept :
        dim {std::forward<dims>(d)...}
    {

    }


    constexpr inline TensorBase(const TensorBase & tensor) noexcept :
        dim(tensor.dim)
    {

    }

    constexpr inline TensorBase(TensorBase && tensor) noexcept :
        dim {std::move(tensor.dim)}
    {

    }

    constexpr inline auto rows(void) const noexcept
        -> const std::enable_if_t<(order > 0_c),
                                  decltype(dim[GEM_START_IDX])> &
    {
        return dim[GEM_START_IDX];
    }

    constexpr inline auto cols(void) const noexcept
        -> const std::enable_if_t<(order > 1_c),
                                  decltype(dim[GEM_START_IDX + 1_c])> &
    {
        return dim[GEM_START_IDX + 1_c];
    }

    constexpr inline auto size(void) const noexcept
    {
        return dim.size();
    }

    constexpr inline auto operator =(const TensorBase & tensor) noexcept
    {
        dim = tensor.dim;
        return *this;
    }

    constexpr inline auto operator =(TensorBase && tensor) noexcept
    {
        dim = std::move(tensor.dim);
        return *this;
    }

    constexpr inline auto operator ==(const TensorBase & tensor) noexcept
    {
        return dim == tensor.dim;
    }

    constexpr inline auto operator !=(const TensorBase & tensor) noexcept
    {
        return dim != tensor.dim;
    }

    constexpr inline auto operator ()(void) const noexcept
        -> const type_t &
    {
        return *this;
    }

    constexpr inline auto operator ()(void) noexcept
        -> type_t &
    {
        return *this;
    }

    constexpr inline auto transpose(void) const noexcept
    {
        return boost::hana::unpack(boost::hana::reverse(dim),
            BOOST_HANA_CONSTEXPR_LAMBDA [](auto... args) {
                return TensorBase<dtype, n_cov, n_con,
                                  decltype(args)...>(args...);
            });
    }

    friend inline auto
    operator <<(std::ostream& os, const TensorBase & tensor)
        -> std::ostream&
    {
        os << "{";
        boost::hana::for_each(
            boost::hana::drop_back(tensor.dim), [&](auto const& d){
                os << d << ", ";
            }
        );
        os << boost::hana::back(tensor.dim);
        return os << "}";
    }

private:

    template<class Archive>
    auto save(Archive & archive) const -> void
    {
        // archive(cereal::make_nvp("data_type",
        //                          gem::demangle(typeid(data_t).name())),
        //         CEREAL_NVP(order),
        //         CEREAL_NVP(contravariants), CEREAL_NVP(covariants),
        //         cereal::make_nvp("size", size()),
        //         cereal::make_nvp("dimensions", dim));
        archive(cereal::make_nvp("data_type",
                                 gem::demangle(typeid(data_t).name())),
                CEREAL_NVP(order),
                CEREAL_NVP(contravariants), CEREAL_NVP(covariants),
                cereal::make_nvp("size", size())
                // cereal::make_nvp("dimensions", dim)
                );
// archive(cereal::make_size_tag(n_con + n_cov));
        // archive(cereal::make_nvp("dimensions", dim));
    }

    template<class Archive>
    auto load(Archive & archive) -> void
    {

    }

};

template <typename dtype, long long n_con, long long n_cov,
          GemDimension... dims>
constexpr
boost::hana::llong<sizeof...(dims)>
TensorBase<dtype, n_con, n_cov, dims...>::order;

template <typename dtype, long long n_con, long long n_cov,
          GemDimension... dims>
constexpr
boost::hana::llong<n_con>
TensorBase<dtype, n_con, n_cov, dims...>::contravariants;

template <typename dtype, long long n_con, long long n_cov,
          GemDimension... dims>
constexpr
boost::hana::llong<n_cov>
TensorBase<dtype, n_con, n_cov, dims...>::covariants;

template <typename dtype, long long n_con, long long n_cov,
          GemDimension... dims>
constexpr boost::hana::type<typename TensorBase<dtype, n_con, n_cov,
                            dims...>::type_t>
TensorBase<dtype, n_con, n_cov, dims...>::type;

template <typename dtype, long long n_con, long long n_cov,
          GemDimension... dims>
constexpr boost::hana::type<typename TensorBase<dtype, n_con, n_cov,
                                                dims...>::data_t>
TensorBase<dtype, n_con, n_cov, dims...>::data_type;

} // namespace gem

#endif // TENSOR_BASE_HPP_INCLUDED