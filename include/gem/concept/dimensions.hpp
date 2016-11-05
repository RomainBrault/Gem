#ifndef CONCEPTS_DIMENSIONS_HPP_INCLUDED
#define CONCEPTS_DIMENSIONS_HPP_INCLUDED

#include <cstddef>
#include <type_traits>

#include <gem/fwd/dimensions.hpp>

#define GEM_USE_LITTERALS true
#define GEM_DEFAULT_DIM_T size_t
#define GEM_DEFAULT_SIZE_T size_t
#define GEM_START_IDX 1_u

// Dimension compatible types
template <class T>
concept bool GemIntegral = std::is_integral<T>::value;

template <class T>
concept bool GemSigned = std::is_signed<T>::value;

template <class T>
concept bool GemUnsigned = !GemSigned<T>;

template <class T>
concept bool GemSignedIntegral = GemIntegral<T> && GemSigned<T>;

template <class T>
concept bool GemUnsignedIntegral = GemIntegral<T> && GemUnsigned<T>;





template <class T, T cv, T max, T min>
concept bool GemValidDimension =
    GemUnsignedIntegral<T> && (max >= cv) && (cv >= min);

template <class T1, T1 cv1, T1 max1, T1 min1,
          class T2, T2 cv2, T2 max2, T2 min2>
concept bool GemDimensionPair =
    GemValidDimension<T1, cv1, max1, min1> &&
    GemValidDimension<T2, cv2, max2, min2>;

template <class T1, T1 cv1, T1 max1, T1 min1,
          class T2>
concept bool GemDimensionIntegralPair =
    GemValidDimension<T1, cv1, max1, min1> &&
    GemIntegral<T2>;

template <class T1,
          class T2, T2 cv2, T2 max2, T2 min2>
concept bool GemIntegralDimensionPair =
    GemIntegral<T1> &&
    GemValidDimension<T2, cv2, max2, min2>;





template <class T, T cv, T max, T min>
concept bool GemValidRuntimeDimension =
    GemUnsignedIntegral<T> && (max > min) && (max >= cv) && (cv >= min);

template <class T, T cv, T max, T min>
concept bool GemValidCompileTimeDimension =
    GemUnsignedIntegral<T> && (max == min) && (max >= cv) && (cv >= min);





template <class T1, T1 cv1, T1 max1, T1 min1,
          class T2, T2 cv2, T2 max2, T2 min2>
concept bool GemCommonDimensionPair =
    GemDimensionPair<T1, cv1, max1, min1, T2, cv2, max2, min2> &&
    !((min1 > max2) || (min2 > max1));

template <class T1, T1 cv, T1 max, T1 min,
          class T2>
concept bool GemCommonDimensionIntegralPair =
    GemDimensionIntegralPair<T1, cv, max, min, T2> &&
    !((min > std::numeric_limits<T2>::max()) ||
      (std::numeric_limits<T2>::min() > max));

template <class T1,
          class T2, T2 cv, T2 max, T2 min>
concept bool GemCommonIntegralDimensionPair =
    GemIntegralDimensionPair<T1, T2, cv, max, min> &&
    !((std::numeric_limits<T1>::min()) > max ||
      (min > std::numeric_limits<T1>::max()));




template <class T1, T1 cv1, T1 max1, T1 min1,
          class T2, T2 cv2, T2 max2, T2 min2>
concept bool GemConvertibleDimensionPair =
    GemValidDimension<T1, cv1, max1, min1> &&
    GemValidDimension<T2, cv2, max2, min2> &&
    (min1 < max2);

#endif  // !CONCEPTS_DIMENSIONS_HPP_INCLUDED
