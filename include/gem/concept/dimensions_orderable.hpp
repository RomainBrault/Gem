#ifndef CONCEPTS_DIMENSION_ORDERABLE_HPP_INCLUDED
#define CONCEPTS_DIMENSION_ORDERABLE_HPP_INCLUDED

#include <boost/hana/less.hpp>
#include <boost/hana/less_equal.hpp>
#include <boost/hana/greater.hpp>
#include <boost/hana/greater_equal.hpp>

#include <gem/concept/dimensions_common.hpp>
#include <gem/fwd/dimensions.hpp>

namespace gem {

template <concepts::Dimension D1, concepts::Dimension D2>
constexpr auto
operator >=(const D1& d1, const D2& d2) noexcept
{
    return d1.value() >= d2.value();
}

concepts::InvalidCommonDimensionPair {D1, D2}
constexpr auto
operator >=(const D1& d1, const D2& d2) noexcept
{
    return d1.value() >= d2.value();
}

template <concepts::Dimension D1, concepts::detail::Integral T2>
constexpr auto
operator >=(const D1& d1, const T2& d2) noexcept
{
    return d1.value() >= d2;
}

template <concepts::detail::Integral T1, concepts::Dimension D2>
constexpr auto
operator >=(const T1& d1, const D2& d2) noexcept
{
    return d1 >= d2.value();
}

template <concepts::Dimension D1, concepts::Dimension D2>
constexpr auto
operator >(const D1& d1, const D2& d2) noexcept
{
    return d1.value() > d2.value();
}

concepts::InvalidCommonDimensionPair {D1, D2}
constexpr auto
operator >(const D1& d1, const D2& d2) noexcept
{
    return d1.value() > d2.value();
}

template <concepts::Dimension D1, concepts::detail::Integral T2>
constexpr auto
operator >(const D1& d1, const T2& d2) noexcept
{
    return d1.value() > d2;
}

template <concepts::detail::Integral T1, concepts::Dimension D2>
constexpr auto
operator >(const T1& d1, const D2& d2) noexcept
{
    return d1 > d2.value();
}

template <concepts::Dimension D1, concepts::Dimension D2>
constexpr auto
operator <=(const D1& d1, const D2& d2) noexcept
{
    return d1.value() <= d2.value();
}

concepts::InvalidCommonDimensionPair {D1, D2}
constexpr auto
operator <=(const D1& d1, const D2& d2) noexcept
{
    return d1.value() <= d2.value();
}

template <concepts::Dimension D1, concepts::detail::Integral T2>
constexpr auto
operator <=(const D1& d1, const T2& d2) noexcept
{
    return d1.value() <= d2;
}

template <concepts::detail::Integral T1, concepts::Dimension D2>
constexpr auto
operator <=(const T1& d1, const D2& d2) noexcept
{
    return d1 <= d2.value();
}

template <concepts::Dimension D1, concepts::Dimension D2>
constexpr auto
operator <(const D1& d1, const D2& d2) noexcept
{
    return d1.value() < d2.value();
}

concepts::InvalidCommonDimensionPair {D1, D2}
constexpr auto
operator <(const D1& d1, const D2& d2) noexcept
{
    return d1.value() < d2.value();
}

template <concepts::Dimension D1, concepts::detail::Integral T2>
constexpr auto
operator <(const D1& d1, const T2& d2) noexcept
{
    return d1.value() < d2;
}

template <concepts::detail::Integral T1, concepts::Dimension D2>
constexpr auto
operator <(const T1& d1, const D2& d2) noexcept
{
    return d1 < d2.value();
}

}  // namespace gem

#endif  // !CONCEPTS_DIMENSION_ORDERABLE_HPP_INCLUDED
