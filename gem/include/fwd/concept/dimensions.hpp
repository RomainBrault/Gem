#ifndef CONCEPTS_DIMENSIONS_HPP_INCLUDED
#define CONCEPTS_DIMENSIONS_HPP_INCLUDED

#include <cstddef>
#include <type_traits>

#define GEM_DEFAULT_DIM_T size_t
#define GEM_DEFAULT_SIZE_T size_t
#define GEM_START_IDX 1_c

// Dimension compatible types
template <class T>
concept bool GemIntegral = std::is_integral<T>::value;

template <class T>
concept bool GemSignedIntegral = GemIntegral<T> && std::is_signed<T>::value;

template <class T>
concept bool GemUnsignedIntegral = GemIntegral<T> && !GemSignedIntegral<T>;

template <class T, T cv, T max, T min>
concept bool GemValidDimension =
	GemUnsignedIntegral<T> && (max >= cv) && (cv >= min);;

template <class T, T cv, T max, T min>
concept bool GemValidRuntimeDimension =
	GemUnsignedIntegral<T> && (max > min) && (max >= cv) && (cv >= min);;

template <class T, T cv, T max, T min>
concept bool GemValidCompileTimeDimension =
	GemUnsignedIntegral<T> && (max == min) && (max >= cv) && (cv >= min);;

#endif // CONCEPTS_DIMENSIONS_HPP_INCLUDED