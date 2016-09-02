#ifndef CONCEPTS_DIMENSIONS_RING_HPP_INCLUDED
#define CONCEPTS_DIMENSIONS_RING_HPP_INCLUDED

#include <limits>
#include <type_traits>

#include <boost/hana/mult.hpp>
#include <boost/hana/one.hpp>
#include <boost/hana/concept/ring.hpp>

#include <gem/fwd/dimensions.hpp>

namespace gem {

// template <GemUnsignedIntegral T1, T1 cv1, T1 max1, T1 min1,
//           GemUnsignedIntegral T2, T2 cv2, T2 max2, T2 min2>
// constexpr inline auto
// operator *(const Dimension<T1, cv1, max1, min1> & d1,
//            const Dimension<T2, cv2, max2, min2> & d2) noexcept
// {
//     using ctype = typename std::common_type<T1, T2>::type;

//     // overflow protection
//     constexpr ctype safe_max {
//         max1 > std::numeric_limits<ctype>::max() / max2 ?
//         std::numeric_limits<ctype>::max() : max1 * max2
//     };

//     constexpr ctype safe_min {
//         min1 > std::numeric_limits<ctype>::max() / min2 ?
//         std::numeric_limits<ctype>::max() : min1 * min2
//     };

//     return Dimension<ctype, safe_min, safe_max, safe_min> {
//             d1.get_value() * d2.get_value()
//     };
// }

// template <GemUnsignedIntegral T1, T1 cv1, T1 max1, T1 min1,
//           typename T2, T2 cv2>
// constexpr inline auto
// operator *(const Dimension<T1, cv1, max1, min1> & d1,
//            const boost::hana::integral_constant<T2, cv2> & d2) noexcept
// {
//     using ctype = typename std::common_type<T1, T2>::type;

//     // overflow protection
//     constexpr ctype safe_max {
//         max1 > std::numeric_limits<ctype>::max() / cv2 ?
//         std::numeric_limits<ctype>::max() : max1 * cv2
//     };

//     constexpr ctype safe_min {
//         min1 > std::numeric_limits<ctype>::max() / cv2 ?
//         std::numeric_limits<ctype>::max() : min1 * cv2
//     };

//     return Dimension<ctype, safe_min, safe_max, safe_min> {
//             d1.get_value() * d2.get_value()
//     };
// }

// template <typename T1, T1 cv1,
//           GemUnsignedIntegral T2, T2 cv2, T2 max2, T2 min2>
// constexpr inline auto
// operator *(const boost::hana::integral_constant<T1, cv1> & d1,
//            const Dimension<T2, cv2, max2, min2> & d2) noexcept
// {
//     using ctype = typename std::common_type<T1, T2>::type;

//     // overflow protection
//     constexpr ctype safe_max {
//         cv1 > std::numeric_limits<ctype>::max() / max2 ?
//         std::numeric_limits<ctype>::max() : cv1 * max2
//     };

//     constexpr ctype safe_min {
//         cv1 > std::numeric_limits<ctype>::max() / min2 ?
//         std::numeric_limits<ctype>::max() : cv1 * min2
//     };

//     return Dimension<ctype, safe_min, safe_max, safe_min> {
//             d1.get_value() * d2.get_value()
//     };
// }

} // namespace gem

BOOST_HANA_NAMESPACE_BEGIN

// template <GemDimension T, GemDimension U>
// struct common<T, U>
// {
//     using type = Dimension<unsigned int, 0, 1000, 0>;
// };

// template <GemDimension T>
// struct one_impl<T> {
//     static constexpr inline auto apply(void)
//     {
//         return gem::Dimension<unsigned long long int, 1, 1, 1> {};
//     }
// };

BOOST_HANA_NAMESPACE_END

#endif // CONCEPTS_DIMENSIONS_RING_HPP_INCLUDED