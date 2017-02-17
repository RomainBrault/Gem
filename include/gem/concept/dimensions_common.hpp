#ifndef CONCEPTS_DIMENSIONS_COMMON_HPP_INCLUDED
#define CONCEPTS_DIMENSIONS_COMMON_HPP_INCLUDED

#include <limits>

#include <boost/hana/core/common.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/max.hpp>
#include <boost/hana/min.hpp>
#include <boost/hana/value.hpp>

#include <gem/fwd/dimensions.hpp>

namespace gem::concepts {

template <Dimension D1, Dimension D2>
concept bool CommonDimensionPair =
    Dimension<D1> && Dimension<D2> &&
    !(boost::hana::value(D1::min > D2::max) ||
      boost::hana::value(D2::min > D1::max));

template <Dimension D1, Dimension D2>
concept bool InvalidCommonDimensionPair =
    Dimension<D1> && Dimension<D2> &&
    (boost::hana::value(D1::min > D2::max) ||
      boost::hana::value(D2::min > D1::max));

template <gem::concepts::detail::Integral T1, Dimension D2>
concept bool CommonIntegralDimensionPair =
    gem::concepts::detail::Integral<T1> && Dimension<D2> &&
    !(std::numeric_limits<T1>::min() > boost::hana::value(D2::max) ||
      boost::hana::value(D2::min) > std::numeric_limits<T1>::max());

template <Dimension D1, gem::concepts::detail::Integral T2>
concept bool CommonDimensionIntegralPair =
    Dimension<D1> && gem::concepts::detail::Integral<T2> &&
    !(boost::hana::value(D1::min) > std::numeric_limits<T2>::max() ||
      std::numeric_limits<T2>::min() > boost::hana::value(D1::max));

}  // namespace gem::concepts

namespace boost::hana {

gem::concepts::CommonDimensionPair {D1, D2}
struct common<D1, D2>
{
    using type = gem::Dimension<boost::hana::common_t<typename D1::dim_t,
                                                      typename D2::dim_t>,
                                value(D1::hint) / 2 + value(D2::hint) / 2,
                                value(max(D1::max, D2::max)),
                                value(min(D1::min, D2::min))>;
};

gem::concepts::InvalidCommonDimensionPair {D1, D2}
struct common<D1, D2>
{
    using type = gem::Dimension<boost::hana::common_t<typename D1::dim_t,
                                                      typename D2::dim_t>,
                                value(D1::hint) / 2 + value(D2::hint) / 2,
                                value(max(D1::max, D2::max)),
                                value(min(D1::min, D2::min))>;
};

gem::concepts::CommonIntegralDimensionPair {T1, D2}
struct common<T1, D2>
{
    using type = boost::hana::common_t<T1, typename D2::dim_t>;
};

gem::concepts::CommonDimensionIntegralPair {D1, T2}
struct common<D1, T2>
{
    using type = boost::hana::common_t<typename D1::dim_t, T2>;
};

gem::concepts::CommonIntegralDimensionPair {T1, D2}
struct common<boost::hana::integral_constant_tag<T1>, D2>
{
    using type = typename decltype(
        if_(D2::max == D2::min,
            type_c<boost::hana::integral_constant_tag<
                boost::hana::common_t<T1, typename D2::dim_t>>>,
            type_c<
                boost::hana::common_t<T1, typename D2::dim_t>>))::type;
};

gem::concepts::CommonDimensionIntegralPair {D1, T2}
struct common<D1, boost::hana::integral_constant_tag<T2>>
{
    using type = typename decltype(
        if_(D1::max == D1::min,
            type_c<boost::hana::integral_constant_tag<
                boost::hana::common_t<typename D1::dim_t, T2>>>,
            type_c<
                boost::hana::common_t<typename D1::dim_t, T2>>))::type;
};

}  // namespace boost::hana

#endif  // !CONCEPTS_DIMENSIONS_COMMON_HPP_INCLUDED
