#ifndef DIMENSIONS_MONOID_HPP_INCLUDED
#define DIMENSIONS_MONOID_HPP_INCLUDED

#include <boost/hana/plus.hpp>

#include <gem/concept/dimensions.hpp>

namespace boost::hana {

// template<typename T1, T1 cv1, typename T2, T2 cv2>
// inline auto
// plus(const gem::Dimension<T1, cv1, cv1, cv1> & d1,
//      const gem::Dimension<T2, cv2, cv2, cv2> & d2)
// {
//     return gem::Dimension<decltype(+d1.type)::type,
//                           boost::hana::value(d1.hint) + boost::hana::value(d1.hint),
//                           boost::hana::value(d1.max) + boost::hana::value(d2.max),
//                           boost::hana::value(d1.min) + boost::hana::value(d2.min)> {};
// }

} // namespace boost::hana

#endif // DIMENSIONS_MONOID_HPP_INCLUDED