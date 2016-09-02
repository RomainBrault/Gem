#ifndef CONCEPTS_DIMENSIONS_MONOID_HPP_INCLUDED
#define CONCEPTS_DIMENSIONS_MONOID_HPP_INCLUDED

#include <limits>
#include <type_traits>

#include <boost/hana/plus.hpp>
#include <boost/hana/zero.hpp>
#include <boost/hana/concept/monoid.hpp>

#include <gem/fwd/dimensions.hpp>

namespace gem {

template< GemUnsignedIntegral T1, T1 cv1, T1 max1, T1 min1,
          GemUnsignedIntegral T2, T2 cv2, T2 max2, T2 min2>
constexpr inline auto
operator +(const Dimension<T1, cv1, max1, min1> & d1,
           const Dimension<T2, cv2, max2, min2> & d2) noexcept
{
    using ctype = typename std::common_type<T1, T2>::type;

    // overflow protection
    constexpr ctype safe_max {
        max1 > std::numeric_limits<ctype>::max() - max2 ?
        std::numeric_limits<ctype>::max() : max1 + max2
    };

    return Dimension<ctype, 0, safe_max, min1 + min2> {
            d1.get_value() + d2.get_value()
    };
}

template <GemUnsignedIntegral T1, T1 cv1,
          GemUnsignedIntegral T2, T2 cv2>
constexpr inline auto
operator +(const Dimension<T1, cv1, cv1, cv1> & d1,
           const Dimension<T2, cv2, cv2, cv2> & d2) noexcept
{
    using ctype = typename std::common_type<T1, T2>::type;

    constexpr auto mult = cv1 + cv2;
    return Dimension<ctype, mult, mult, mult> {
    };
}

} // namespace gem

BOOST_HANA_NAMESPACE_BEGIN

template <GemUnsignedIntegral T1, T1 cv1, T1 max1, T1 min1,
          GemUnsignedIntegral T2, T2 cv2, T2 max2, T2 min2>
struct plus_impl<gem::Dimension<T1, cv1, max1, min1>,
                 gem::Dimension<T2, cv2, max2, min2>>
{
    using ctype = typename std::common_type<T1, T2>::type;

    template <typename D1, typename D2>
    static constexpr inline auto apply(D1&& d1, D2&& d2)
    {
        return d1 + d2;
    }

};

template<GemUnsignedIntegral T, T cv, T max, T min>
struct zero_impl<gem::Dimension<T, cv, max, min>> {
    static constexpr inline auto apply(void)
    {
        return gem::Dimension<T, 0, 0, 0> {};
    }
};

BOOST_HANA_NAMESPACE_END

#endif // CONCEPTS_DIMENSIONS_MONOID_HPP_INCLUDED
