#ifndef DIMENSIONS_TUPLE_HPP_INCLUDED
#define DIMENSIONS_TUPLE_HPP_INCLUDED

#include <type_traits>

#include <boost/hana/minus.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/transform.hpp>
#include <boost/hana/fold.hpp>

#include <boost/hana/experimental/printable.hpp>

#include <gem/dimensions.hpp>
#include <gem/fwd/dimensions_tuple.hpp>

namespace gem {

template <bool T_flag, GemDimension... dims>
class DimensionTuple :
    public boost::hana::tuple<dims...>
{
private:

    template <GemDimension d1, GemDimension... rd>
    struct gem_dim_common_type {
        using type =
            std::common_type_t<typename d1::dim_t,
                               typename gem_dim_common_type<rd...>::type>;
    };

    template <GemDimension d1>
    struct gem_dim_common_type<d1> {
        using type = typename d1::dim_t;
    };


public:
    using type_t = DimensionTuple<T_flag, dims...>;
    using base_t = boost::hana::tuple<dims...>;
    using common_t = typename gem_dim_common_type<dims...>::type;

public:

    static_assert(sizeof...(dims) > 0,
                  "At least one dimension must be specified.");

    using base_t::tuple;

    constexpr inline auto get_value(void) const noexcept
    {
        auto _value = [](auto && d) {
            return d.get_value();
        };
        return boost::hana::transform(*this, _value);
    }

    static constexpr inline auto get_max(void) noexcept
    {

        BOOST_HANA_CONSTEXPR_LAMBDA auto _max = [](auto && d) {
            return decltype(+d)::type::get_max();
        };
        return boost::hana::transform(boost::hana::tuple_t<dims...>, _max);
    }

    static constexpr inline auto get_min(void) noexcept
    {
        BOOST_HANA_CONSTEXPR_LAMBDA auto _min = [](auto && d) {
            return decltype(+d)::type::get_min();
        };
        return boost::hana::transform(boost::hana::tuple_t<dims...>, _min);
    }

    constexpr inline auto size(void) const noexcept {
        BOOST_HANA_CONSTEXPR_LAMBDA auto _mult = [](auto && acc,
                                                    auto && d)
        {
            return acc * d;
        };


        BOOST_HANA_CONSTEXPR_LAMBDA auto _mult_c = [](auto && acc,
                                                      auto && d)
        {
            constexpr common_t max = std::numeric_limits<common_t>::max();
            bool overflow = (acc > max / static_cast<common_t>(d)) &&
                            !(acc == boost::hana::integral_c<common_t, 0>);
            return overflow ? boost::hana::integral_c<common_t, 0> : acc * d;
        };

        BOOST_HANA_CONSTEXPR_LAMBDA auto val = boost::hana::fold(get_value(), _mult);
        BOOST_HANA_CONSTEXPR_LAMBDA auto max = boost::hana::fold(get_max(), _mult_c);
        BOOST_HANA_CONSTEXPR_LAMBDA auto min = boost::hana::fold(get_min(), _mult);
        return Dimension<common_t, min, max, min> { val };
    }

    constexpr inline auto operator [](const auto & idx) const noexcept
        -> const std::enable_if_t<T_flag,
            decltype(base_t::operator[] (
                boost::hana::llong_c<sizeof...(dims)> -
                                     idx + GEM_START_IDX - 1_c))> &
    {
        return base_t::operator[] (
            boost::hana::llong_c<sizeof...(dims)> -
                                 idx + GEM_START_IDX - 1_c);
    }

    constexpr inline auto operator [](const auto & idx) const noexcept
        -> const std::enable_if_t<!T_flag,
            decltype(base_t::operator[] (idx - GEM_START_IDX))> &
    {
        return base_t::operator[] (idx - GEM_START_IDX);
    }
};

} // namespage gem

#endif // DIMENSIONS_TUPLE_HPP_INCLUDED