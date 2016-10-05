#ifndef DIMENSIONS_TO_HPP_INCLUDED
#define DIMENSIONS_TO_HPP_INCLUDED

#include <limits>
#include <algorithm>

#include <boost/hana/core/to.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/assert.hpp>

#include <gem/fwd/dimensions.hpp>
#include <gem/concept/dimensions.hpp>
#include <gem/concept/dimensions_tag.hpp>

namespace std {
    template<class T, class Compare>
    constexpr auto clamp(const T& v, const T& lo, const T& hi, Compare comp)
        -> const T&
    {
        return assert(!comp(hi, lo)), comp(v, lo) ? lo : comp(hi, v) ? hi : v;
    }

    template<class T>
    constexpr auto clamp(const T& v, const T& lo, const T& hi)
        -> const T&
    {
        return clamp( v, lo, hi, std::less<>() );
    }
}

namespace boost::hana {

template<typename T1, /* To */
         typename T2, T2 max_cv2, T2 min_cv2 /* From */>
struct to_impl<T1, // To.
               gem::dimension_tag<T2, max_cv2, min_cv2>, // From.
               when<is_convertible<T2, T1>::value &&
                    (max_cv2 <= std::numeric_limits<T1>::max()) &&
                    (min_cv2 >= std::numeric_limits<T1>::min())>> :
    embedding<is_embedded<T2, T1>::value &&
              (std::numeric_limits<T1>::max() >=
                std::numeric_limits<T2>::max()) &&
              (std::numeric_limits<T1>::min() <=
                std::numeric_limits<T2>::min())>
{
    template<T2 cv>
    static inline auto
    apply(const gem::Dimension<T2, cv, max_cv2, min_cv2> d)
        -> T1
    {
        return d.value();
    }
};

template<typename T1, T1 max_cv1, T1 min_cv1 /* To */,
         GemIntegral T2 /* From */>
struct to_impl<gem::dimension_tag<T1, max_cv1, min_cv1>, // To.
               T2, // From.
               when<is_convertible<T2, T1>::value>> :
    embedding<is_embedded<T2, T1>::value &&
              (std::numeric_limits<T1>::max() >=
                std::numeric_limits<T2>::max()) &&
              (std::numeric_limits<T1>::min() <=
                std::numeric_limits<T2>::min())>
{
    static inline auto
    apply(const T2 d)
        -> gem::Dimension<T1, min_cv1, max_cv1, min_cv1>
    {
        return gem::Dimension<T1, min_cv1,
                              max_cv1, min_cv1> {d};
    }
};

template<typename T1, /* To */
         typename T2, T2 max_cv2, T2 min_cv2 /* From */>
struct to_impl<integral_constant_tag<T1>, // To.
               gem::dimension_tag<T2, max_cv2, min_cv2>, // From.
               when<is_convertible<T2, T1>::value &&
                    (max_cv2 <= std::numeric_limits<T1>::max()) &&
                    (min_cv2 >= std::numeric_limits<T1>::min())>> :
    embedding<is_embedded<T2, T1>::value &&
              (std::numeric_limits<T1>::max() >=
                std::numeric_limits<T2>::max()) &&
              (std::numeric_limits<T1>::min() <=
                std::numeric_limits<T2>::min())>
{
    template<T2 cv>
    static inline auto
    apply(const gem::Dimension<T2, cv, max_cv2, min_cv2> d)
        -> integral_constant<T1, cv>
    {
        return to<integral_constant_tag<T1>>(d.value());
    }
};

/* Convert compile time dimension to a runtime dimension as well as runtime
   to runtime */
template<typename T1, T1 max_cv1, T1 min_cv1 /* To */,
         typename T2, T2 max_cv2, T2 min_cv2 /* From */>
struct to_impl<gem::dimension_tag<T1, max_cv1, min_cv1>, // To.
               gem::dimension_tag<T2, max_cv2, min_cv2>, // From.
               when<is_convertible<T2, T1>::value &&
                    (max_cv2 <= std::numeric_limits<T1>::max()) &&
                    (min_cv2 >= std::numeric_limits<T1>::min())>> :
    embedding<is_embedded<T2, T1>::value &&
              (std::numeric_limits<T1>::max() >=
                std::numeric_limits<T2>::max()) &&
              (std::numeric_limits<T1>::min() <=
                std::numeric_limits<T2>::min())>
{
    template<T2 cv>
    static inline auto
    apply(const gem::Dimension<T2, cv, max_cv2, min_cv2> d)
        -> gem::Dimension<T1, std::clamp<T1>(cv, min_cv1, max_cv1),
                          max_cv1, min_cv1>
    {
        return gem::Dimension<T1, std::clamp<T1>(cv, min_cv1, max_cv1),
                              max_cv1, min_cv1> {d.value()};
    }
};


// Convert compile time dimension to a compile time dimension.
template<typename T1, T1 cv1, /* To */
         typename T2, T2 max_cv2, T2 min_cv2 /* From */>
struct to_impl<gem::dimension_tag<T1, cv1, cv1>, // To.
               gem::dimension_tag<T2, max_cv2, min_cv2>, // From.
               when<is_convertible<T2, T1>::value &&
                    (max_cv2 <= std::numeric_limits<T1>::max()) &&
                    (min_cv2 >= std::numeric_limits<T1>::min())>> :
    embedding<is_embedded<T2, T1>::value &&
              (std::numeric_limits<T1>::max() >=
                std::numeric_limits<T2>::max()) &&
              (std::numeric_limits<T1>::min() <=
                std::numeric_limits<T2>::min())>
{
    template<T2 cv>
    static inline auto
    apply(const gem::Dimension<T2, cv, max_cv2, min_cv2> d)
        -> gem::Dimension<T1, cv1, cv1, cv1>
    {
        return gem::Dimension<T1, cv1, cv1, cv1> {};
    }
};

} // namespace boost::hana

#endif // DIMENSIONS_TO_HPP_INCLUDED