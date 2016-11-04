#ifndef DIMENSIONS_TO_HPP_INCLUDED
#define DIMENSIONS_TO_HPP_INCLUDED

#include <limits>
#include <algorithm>

#include <boost/hana/core/to.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/assert.hpp>

#include <gem/fwd/dimensions.hpp>
#include <gem/concept/dimensions.hpp>

namespace boost::hana {

GemConvertibleDimensionPair {T1, cv1, max1, min1, T2, cv2, max2, min2}
struct to_impl<gem::Dimension<T1, cv1, max1, min1>, // To.
               gem::Dimension<T2, cv2, max2, min2>> : // From.
    embedding<is_embedded<T2, T1>::value && (max2 <= max1) && (min2 >= min1)>
{
    static constexpr inline auto
    apply(const gem::Dimension<T2, cv2, max2, min2>& d)
        -> gem::Dimension<T1, cv1, max1, min1>
    {
        return gem::Dimension<T1, cv1, max1, min1> {d.value()};
    }
};

template<GemUnsignedIntegral T1, T1 cv1, GemUnsignedIntegral T2, T2 cv2>
struct to_impl<gem::Dimension<T1, cv1, cv1, cv1>, // To.
               gem::Dimension<T2, cv2, cv2, cv2>, // From.
               when<(cv1 == cv2)>> :
    embedding<is_embedded<T2, T1>::value>
{
    static constexpr inline auto
    apply(const gem::Dimension<T2, cv2, cv2, cv2>& d)
        -> gem::Dimension<T1, cv1, cv1, cv1>
    {
        return gem::Dimension<T1, cv1, cv1, cv1> {};
    }
};

template<GemIntegral T1, GemUnsignedIntegral T2, T2 cv2, T2 max2, T2 min2>
struct to_impl<T1, // To.
               gem::Dimension<T2, cv2, max2, min2>> : // From.
    embedding<is_embedded<T2, T1>::value &&
              (std::numeric_limits<T1>::max() >= max2) &&
              (std::numeric_limits<T1>::min() <= min2)>
{
    static constexpr inline auto
    apply(const gem::Dimension<T2, cv2, max2, min2>& d) -> T1
    {
        return d.value();
    }
};

template<GemIntegral T1, GemUnsignedIntegral T2, T2 cv>
struct to_impl<integral_constant_tag<T1>, // To.
               gem::Dimension<T2, cv, cv, cv>> : // From.
    embedding<is_embedded<T2, T1>::value>
{
    static constexpr inline auto
    apply(const gem::Dimension<T2, cv, cv, cv>& d)
        -> integral_constant<T1, cv>
    {
        return integral_c<T1, cv>;
    }
};

template<GemUnsignedIntegral T1, T1 cv, T1 max, T1 min, GemIntegral T2>
struct to_impl<gem::Dimension<T1, cv, max, min>, // To.
               T2>: // From.
    embedding<is_embedded<T2, T1>::value &&
              (std::numeric_limits<T1>::max() >=
               std::numeric_limits<T2>::max()) &&
              (std::numeric_limits<T1>::min() <=
               std::numeric_limits<T2>::min())>
{
    static constexpr inline auto
    apply(const T2& d) -> gem::Dimension<T1, cv, max, min>
    {
        return gem::Dimension<T1, cv, max, min> {d};
    }
};

template<GemUnsignedIntegral T1, T1 cv, T1 max, T1 min, GemIntegral T2>
struct to_impl<gem::Dimension<T1, cv, max, min>, // To.
               boost::hana::integral_constant<T2, cv>>: // From.
    embedding<is_embedded<T2, T1>::value &&
              (max >= std::numeric_limits<T2>::max()) &&
              (min <= std::numeric_limits<T2>::min())>
{
    static constexpr inline auto
    apply(const boost::hana::integral_constant<T2, cv>& d)
        -> gem::Dimension<T1, cv, max, min>
    {
        return gem::Dimension<T1, cv, max, min> {d};
    }
};

} // namespace boost::hana

#endif // DIMENSIONS_TO_HPP_INCLUDED