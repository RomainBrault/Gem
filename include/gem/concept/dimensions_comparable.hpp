#ifndef CONCEPTS_DIMENSIONS_COMPARABLE_HPP_INCLUDED
#define CONCEPTS_DIMENSIONS_COMPARABLE_HPP_INCLUDED

#include <boost/hana/equal.hpp>
#include <boost/hana/not_equal.hpp>
#include <boost/hana/core/common.hpp>

#include <gem/concept/dimensions_common.hpp>
#include <gem/fwd/dimensions.hpp>

namespace gem {

gem::concepts::CommonDimensionPair {D1, D2}
constexpr auto
operator ==(const D1& d1, const D2& d2) noexcept
{
    return d1.value() == d2.value();
}

gem::concepts::InvalidCommonDimensionPair {D1, D2}
constexpr auto
operator ==(const D1&, const D2&) noexcept
{
    return boost::hana::false_c;
}

gem::concepts::CommonDimensionIntegralPair {D1, T2}
constexpr auto
operator ==(const D1& d1, const T2& d2) noexcept
{
    return d1.value() == d2;
}

gem::concepts::CommonIntegralDimensionPair {T1, D2}
constexpr auto
operator ==(const T1& d1, const D2& d2) noexcept
{
    return d1 == d2.value();
}

gem::concepts::CommonDimensionPair {D1, D2}
constexpr auto
operator !=(const D1& d1, const D2& d2) noexcept
{
    return d1.value() != d2.value();
}

gem::concepts::InvalidCommonDimensionPair {D1, D2}
constexpr auto
operator !=(const D1&, const D2&) noexcept
{
    return boost::hana::true_c;
}

gem::concepts::CommonDimensionIntegralPair {D1, T2}
constexpr auto
operator !=(const D1& d1, const T2& d2) noexcept
{
    return d1.value() != d2;
}

gem::concepts::CommonIntegralDimensionPair {T1, D2}
constexpr auto
operator !=(const T1& d1, const D2& d2) noexcept
{
    return d1 != d2.value();
}

}  // namespace gem

#endif  // !CONCEPTS_DIMENSIONS_COMPARABLE_HPP_INCLUDED
