#ifndef CONCEPTS_DIMENSIONS_TO_HPP_INCLUDED
#define CONCEPTS_DIMENSIONS_TO_HPP_INCLUDED

#include <limits>
#include <algorithm>

#include <boost/hana/core/to.hpp>
#include <boost/hana/value.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/assert.hpp>

#include <gem/fwd/dimensions.hpp>

namespace gem::concepts {

template <Dimension D1, Dimension D2>
concept bool ConvertibleDimensionPair =
    Dimension<D1> && Dimension<D2> &&
    boost::hana::value((D1::min <= D2::max) && (D1::max >= D2::min));

template <detail::Integral T1, Dimension D2>
concept bool ConvertibleIntegralDimensionPair =
    gem::concepts::detail::Integral<T1> && Dimension<D2> &&
    std::numeric_limits<T1>::min() <= boost::hana::value(D2::max) &&
    std::numeric_limits<T1>::max() >= boost::hana::value(D2::min);

template <Dimension D1, detail::Integral T2>
concept bool ConvertibleDimensionIntegralPair =
    Dimension<D1> && gem::concepts::detail::Integral<T2> &&
    boost::hana::value(D1::min) <= std::numeric_limits<T2>::max() &&
    boost::hana::value(D1::max) >= std::numeric_limits<T2>::min();

template <detail::Integral T1, CompileTimeDimension D2>
concept bool ConvertibleIntegralCompileTimeDimensionPair =
    gem::concepts::detail::Integral<T1> && CompileTimeDimension<D2> &&
    std::numeric_limits<T1>::min() <= boost::hana::value(D2::max) &&
    std::numeric_limits<T1>::max() >= boost::hana::value(D2::min);

template <detail::Integral T1, CompileTimeDimension D2>
concept bool ConvertibleIntegralRuntimeDimensionPair =
    gem::concepts::detail::Integral<T1> && RuntimeDimension<D2> &&
    std::numeric_limits<T1>::min() <= boost::hana::value(D2::max) &&
    std::numeric_limits<T1>::max() >= boost::hana::value(D2::min);

}  // namespace gem::concepts

namespace boost::hana {

//////////////////////////////////////////////////////////////////////////
// Dimension <-> Dimension
//////////////////////////////////////////////////////////////////////////

gem::concepts::ConvertibleDimensionPair {D1, D2}
struct to_impl<D1, D2> : // To <- from.
    embedding<is_embedded<typename D2::dim_t, typename D1::dim_t>::value &&
              value((D2::max <= D1::max) && (D2::min >= D1::min))>
{
    static constexpr inline auto
    apply(const D2& d) noexcept -> D1
    {
        return {d.value()};
    }
};

//////////////////////////////////////////////////////////////////////////
// Dimension -> Itegral
//////////////////////////////////////////////////////////////////////////

gem::concepts::ConvertibleIntegralDimensionPair {T1, D2}
struct to_impl<T1, D2> : // To <- from.
    embedding<is_embedded<typename D2::dim_t, T1>::value &&
              (std::numeric_limits<T1>::max() >= value(D2::max)) &&
              (std::numeric_limits<T1>::min() <= value(D2::min))>
{
    static constexpr inline auto
    apply(const D2& d) noexcept -> T1
    {
        return {d.value()};
    }
};

//////////////////////////////////////////////////////////////////////////
// Itegral -> Dimension
//////////////////////////////////////////////////////////////////////////

gem::concepts::ConvertibleDimensionIntegralPair {D1, T2}
struct to_impl<D1, T2> : // To <- from.
    embedding<is_embedded<T2, typename D1::dim_t>::value &&
              (value(D1::max) >= std::numeric_limits<T2>::max()) &&
              (value(D1::min) <= std::numeric_limits<T2>::min())>
{
    static constexpr inline auto
    apply(const T2& d) noexcept -> D1
    {
        return {d};
    }
};

//////////////////////////////////////////////////////////////////////////
// Dimension -> Ingegral constant
//////////////////////////////////////////////////////////////////////////

gem::concepts::ConvertibleIntegralCompileTimeDimensionPair {T1, D2}
struct to_impl<integral_constant_tag<T1>, D2> : // To <- from.
    embedding<is_embedded<typename D2::dim_t, T1>::value>
{
    static constexpr inline auto
    apply(const D2&) noexcept -> integral_constant<T1, value(D2::hint)>
    {
        return {};
    }
};

//////////////////////////////////////////////////////////////////////////
// Ingegral constant -> Dimension
//////////////////////////////////////////////////////////////////////////

gem::concepts::ConvertibleDimensionIntegralPair {D1, T2}
struct to_impl<D1, integral_constant_tag<T2>>: // To <- from.
    embedding<is_embedded<T2, typename D1::dim_t>::value &&
              (value(D1::max) >= std::numeric_limits<T2>::max()) &&
              (value(D1::min) <= std::numeric_limits<T2>::min())>
{
    template <T2 cv>
    static constexpr inline auto
    apply(const boost::hana::integral_constant<T2, cv>& d) noexcept -> D1
    {
        return {d};
    }
};

//////////////////////////////////////////////////////////////////////////
// Dimension <-> Dimension tag
//////////////////////////////////////////////////////////////////////////

gem::concepts::ConvertibleIntegralCompileTimeDimensionPair {T1, D2}
struct to_impl<gem::CompileTimeDimensionTag<T1>, D2> : // To <- from.
    embedding<is_embedded<typename D2::dim_t, T1>::value>
{
    static constexpr inline auto
    apply(const D2&) noexcept ->
        gem::Dimension<T1, value(D2::hint), value(D2::max), value(D2::min)>
    {
        return {};
    }
};

gem::concepts::ConvertibleIntegralRuntimeDimensionPair {T1, D2}
struct to_impl<gem::RuntimeDimensionTag<T1>, D2> : // To <- from.
    embedding<is_embedded<typename D2::dim_t, T1>::value>
{
    static constexpr inline auto
    apply(const D2& d2) noexcept ->
        gem::Dimension<T1, value(D2::hint), value(D2::max), value(D2::min)>
    {
        return {d2.value()};
    }
};

gem::concepts::ConvertibleIntegralCompileTimeDimensionPair {T1, D2}
struct to_impl<gem::RuntimeDimensionTag<T1>, D2> : // To <- from.
    embedding<is_embedded<typename D2::dim_t, T1>::value>
{
    static constexpr inline auto
    apply(const D2& d2) noexcept ->
        gem::Dimension<T1, value(D2::hint), value(D2::max), value(D2::min)>
    {
        return {d2.value()};
    }
};

}  // namespace boost::hana

#endif  // !CONCEPTS_DIMENSIONS_TO_HPP_INCLUDED
