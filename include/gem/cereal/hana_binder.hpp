#ifndef HANA_BINDER_HPP_INCLUDED
#define HANA_BINDER_HPP_INCLUDED

#include <cereal/access.hpp>
#include <boost/hana/integral_constant.hpp>

namespace cereal {

// template<typename T, T v>
// auto save_minimal(const auto &,
//                   const boost::hana::integral_constant<T, v> & m) -> T
// {
//   return v;
// }

// template<typename T, T v>
// auto load_minimal(const auto &,
//                   boost::hana::integral_constant<T, v> &,
//                   const auto & value) -> void
// {
//   assert(v == value);
// }

} // namespace cereal

#endif  // !HANA_BINDER_HPP_INCLUDED
