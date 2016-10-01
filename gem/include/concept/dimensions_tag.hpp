#ifndef DIMENSIONS_TAG_HPP_INCLUDED
#define DIMENSIONS_TAG_HPP_INCLUDED

#include <limits>

namespace gem {

template<typename T,
         T cv_max = std::numeric_limits<T>::max(),
         T cv_min = std::numeric_limits<T>::min()>
struct dimension_tag
{

};

} // namespace gem

#endif // DIMENSIONS_TAG_HPP_INCLUDED