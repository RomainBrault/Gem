#ifndef TENSOR_BASE_HPP_INCLUDED
#define TENSOR_BASE_HPP_INCLUDED

#include <ostream>

#include <boost/hana/type.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/reverse.hpp>
#include <boost/hana/back.hpp>
#include <boost/hana/drop_back.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/greater.hpp>

#include <gem/dimensions_tuple.hpp>

namespace gem {

template <typename dtype, GemDimension... dims>
class TensorBase
{

public:
    using type_t = TensorBase;
    using data_t = dtype;

    using dimension_tuple_t = DimensionTuple<false, dims...>;
    using dimension_tuple_common_t = typename dimension_tuple_t::common_t;

    template<typename n_dtype, GemDimension... n_dims>
    friend class TensorBase;

public:
    static constexpr
    boost::hana::type<type_t> type {};

    static constexpr
    boost::hana::type<data_t> data_type {};

    static constexpr
    boost::hana::llong<sizeof...(dims)> n_dims {};

    dimension_tuple_t dim;

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
        -> const std::enable_if_t<(n_dims > 0_c),
                                  decltype(dim[GEM_START_IDX])> &
    {
        return dim[GEM_START_IDX];
    }

    constexpr inline auto cols(void) const noexcept
        -> const std::enable_if_t<(n_dims > 1_c),
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
                return TensorBase<dtype, decltype(args)...>(args...);
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
};

template <typename dtype, GemDimension... dims>
constexpr
boost::hana::llong<sizeof...(dims)>
TensorBase<dtype, dims...>::n_dims;

template <typename dtype, GemDimension... dims>
constexpr boost::hana::type<typename TensorBase<dtype, dims...>::type_t>
TensorBase<dtype, dims...>::type;

template <typename dtype, GemDimension... dims>
constexpr boost::hana::type<typename TensorBase<dtype, dims...>::data_t>
TensorBase<dtype, dims...>::data_type;

} // namespace gem

#endif // TENSOR_BASE_HPP_INCLUDED