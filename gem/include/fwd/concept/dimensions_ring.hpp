#ifndef FWD_CONCEPTS_DIMENSIONS_RING_HPP_INCLUDED
#define FWD_CONCEPTS_DIMENSIONS_RING_HPP_INCLUDED

#include <gem/fwd/dimensions.hpp>

namespace gem {

template <GemUnsignedIntegral T1, T1 cv1, T1 max1, T1 min1,
          GemUnsignedIntegral T2, T2 cv2, T2 max2, T2 min2>
constexpr inline auto
operator *(const Dimension<T1, cv1, max1, min1> & d1,
           const Dimension<T2, cv2, max2, min2> & d2) noexcept;

template <GemUnsignedIntegral T1, T1 cv1,
          GemUnsignedIntegral T2, T2 cv2>
constexpr inline auto
operator *(const Dimension<T1, cv1, cv1, cv1> & d1,
           const Dimension<T2, cv2, cv2, cv2> & d2) noexcept;

} // namespace gem

#endif // FWD_CONCEPTS_DIMENSIONS_RING_HPP_INCLUDED