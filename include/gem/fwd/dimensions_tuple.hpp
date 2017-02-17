#ifndef FWD_DIMENSIONS_TUPLE_HPP_INCLUDED
#define FWD_DIMENSIONS_TUPLE_HPP_INCLUDED

#include <gem/concept/dimensions_tuple.hpp>
#include <gem/fwd/dimensions.hpp>

namespace gem::concepts {

template <bool T_flag, long long n_cov, long long n_con, class... dims>
concept bool DimensionTuple = std::is_same_v<T_flag, bool> &&
                              Dimension<dims...>;

}  // namespace gem::concepts

namespace gem {

gem::concepts::DimensionTuple {T_flag, n_con, n_cov, ...dims}
class DimensionTuple;

}  // namespage gem

#endif  // !FWD_DIMENSIONS_TUPLE_HPP_INCLUDED
