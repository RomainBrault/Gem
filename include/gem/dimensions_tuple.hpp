#ifndef GEM_DIMENSIONS_TUPLE_HPP_INCLUDED
#define GEM_DIMENSIONS_TUPLE_HPP_INCLUDED

#define BOOST_HANA_CONFIG_ENABLE_STRING_UDL

#include <type_traits>

#include <boost/hana/assert.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/minus.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/transform.hpp>
#include <boost/hana/fold.hpp>
#include <boost/hana/string.hpp>

#include <cereal/cereal.hpp>

#include <gem/litterals.hpp>
#include <gem/fwd/dimensions_tuple.hpp>

namespace gem {


gem::concepts::DimensionTuple {T_flag, n_con, n_cov, ...dims}
class DimensionTuple :
    public boost::hana::tuple<dims...>
{
private:

    template <gem::concepts::Dimension d1, gem::concepts::Dimension... rd>
    struct gem_dim_common_type {
        using type =
            std::common_type_t<typename d1::dim_t,
                               typename gem_dim_common_type<rd...>::type>;
    };

    // template <gem::concepts::Dimension d1>
    gem::concepts::Dimension {d1}
    struct gem_dim_common_type<d1> {
        using type = typename d1::dim_t;
    };


public:
    using type_t = DimensionTuple<T_flag, n_con, n_cov, dims...>;
    using base_t = boost::hana::tuple<dims...>;
    using common_t = typename gem_dim_common_type<dims...>::type;

    friend class cereal::access;

public:

    static constexpr BOOST_HANA_CONSTANT_CHECK_MSG(
        (boost::hana::ullong_c<0> <
         boost::hana::ullong_c<sizeof...(dims)>),
        "At least one dimension must be specified.");

    using base_t::tuple;

    constexpr inline auto
    value(void) const noexcept
    {
        constexpr auto _value = [](auto && d) {
            return d.value();
        };
        return boost::hana::transform(*this, _value);
    }

    static constexpr inline auto
    get_max(void) noexcept
    {

        constexpr auto _max = [](auto && d) {
            return decltype(+d)::type::get_max();
        };
        return boost::hana::transform(boost::hana::tuple_t<dims...>, _max);
    }

    static constexpr inline auto
    get_min(void) noexcept
    {
        constexpr auto _min = [](auto && d) {
            return decltype(+d)::type::get_min();
        };
        return boost::hana::transform(boost::hana::tuple_t<dims...>, _min);
    }

    constexpr inline auto size(void) const noexcept {
        constexpr auto _mult = [](auto && acc, auto && d) {
            return acc * d;
        };
        return boost::hana::fold(*this, _mult);
    }

    constexpr inline auto operator [](const auto & idx) const noexcept
        -> const std::enable_if_t<T_flag,
            decltype(base_t::operator[] (
                boost::hana::ullong_c<sizeof...(dims)> -
                                      idx + GEM_START_IDX -
                                      boost::hana::ullong_c<1>))> &
    {
        return base_t::operator[] (
            boost::hana::ullong_c<sizeof...(dims)> -
                                  idx + GEM_START_IDX -
                                  boost::hana::ullong_c<1>);
    }

    constexpr inline auto operator [](const auto & idx) const noexcept
        -> const std::enable_if_t<!T_flag,
            decltype(base_t::operator[] (idx - GEM_START_IDX))> &
    {
        return base_t::operator[] (idx - GEM_START_IDX);
    }

private:
    template<class Archive>
    auto save(Archive & archive) const -> void
    {
        // archive(cereal::make_size_tag(n_con));
        boost::hana::ullong_c<n_con>.times.with_index(
            [this, &archive](auto index) {
                // TODO: make the string concatenation compile time.
                archive(cereal::make_nvp("contravariant",
                                         this->operator[] (GEM_START_IDX + index)));
        });
        boost::hana::ullong_c<n_cov>.times.with_index(
            [this, &archive](auto index) {
                // TODO: make the string concatenation compile time.
                archive(cereal::make_nvp("covariant",
                                         this->operator[] (GEM_START_IDX + boost::hana::ullong_c<n_con> + index)));
        });
    }

    template<class Archive>
    auto load(Archive & archive) -> void
    {

    }
};

}  // namespage gem

#endif  // !GEM_DIMENSIONS_TUPLE_HPP_INCLUDED
