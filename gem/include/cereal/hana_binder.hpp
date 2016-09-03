#ifndef HANA_BINDER_HPP_INCLUDED
#define HANA_BINDER_HPP_INCLUDED

#include <cereal/access.hpp>
#include <boost/hana/integral_constant.hpp>

namespace cereal {

template<class Archive, typename T, T v>
auto save_minimal(const Archive &,
                  const boost::hana::integral_constant<T, v> & m) -> T
{
  return v;
}

template<class Archive, typename T, T v>
auto load_minimal(const Archive &,
                  boost::hana::integral_constant<T, v> &,
                  const auto & value) -> void
{
  assert(v == value);
}

}

#endif // HANA_BINDER_HPP_INCLUDED