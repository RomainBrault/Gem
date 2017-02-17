#ifndef CONCEPT_DIMENSIONS_HPP_INCLUDED
#define CONCEPT_DIMENSIONS_HPP_INCLUDED

#include <limits>
#include <cstddef>
#include <type_traits>

#define GEM_USE_LITTERALS true
#define GEM_DEFAULT_DIM_T size_t
#define GEM_DEFAULT_SIZE_T size_t
#define GEM_START_IDX 1_u

namespace gem::concepts::detail {

// Dimension compatible types
template <class T>
concept bool Integral = std::is_integral<T>::value /* Defer positivity check to
                                                    * runtime. Don't forget to
                                                    * check it... */;

template <Integral T, T cv>
concept bool IntegralConstant = true;

Integral {T}
concept bool UnsignedIntegral = !std::is_signed<T>::value;

IntegralConstant {T, cv}
concept bool UnsignedIntegralConstant = !std::is_signed<T>::value;

template <UnsignedIntegral T, T cv, T max, T min>
concept bool Dimension = (max >= cv) && (cv >= min);

Dimension {T, cv, max, min}
concept bool RuntimeDimension = (max > min);

Dimension {T, cv, max, min}
concept bool CompileTimeDimension = (max == min);






template <class T1, T1 cv1, T1 max1, T1 min1,
          class T2, T2 cv2, T2 max2, T2 min2>
concept bool DimensionPair = Dimension<T1, cv1, max1, min1> &&
                             Dimension<T2, cv2, max2, min2>;

template <class T1, T1 cv1, T1 max1, T1 min1,
          class T2>
concept bool DimensionIntegralPair = Dimension<T1, cv1, max1, min1> &&
                                     Integral<T2>;

template <class T1,
          class T2, T2 cv2, T2 max2, T2 min2>
concept bool IntegralDimensionPair = Integral<T1> &&
                                     Dimension<T2, cv2, max2, min2>;

}  // namespage gem::concepts::detail

#endif  // !CONCEPT_DIMENSIONS_HPP_INCLUDED
