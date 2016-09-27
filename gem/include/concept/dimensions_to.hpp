#ifndef DIMENSIONS_TO_HPP_INCLUDED
#define DIMENSIONS_TO_HPP_INCLUDED

#include <limits>

#include <boost/hana/core/to.hpp>
#include <boost/hana/core/when.hpp>
#include <boost/hana/assert.hpp>

#include <gem/fwd/dimensions.hpp>
#include <gem/concept/dimensions.hpp>
#include <gem/concept/dimensions_tag.hpp>

namespace boost::hana {

// Convert any dimensions to a runtime dimension.
// template<typename T1, T1 max_cv, T1 min_cv /* To */,
//          typename T2, T2 max_cv, T2 min_cv /* From */>
// struct to_impl<gem::runtime_dimension_tag<T1>, // To.
//                gem::compile_time_dimension_tag<T2>, // From.
//                when<is_convertible<T2, T1>::value>> :
//     embedding<is_embedded<T2, T1>::value>
// {
//     template<T2 cv>
//     static inline auto
//     apply(const gem::Dimension<T2, cv, cv, cv> xs)
//         -> gem::Dimension<T1, cv, cv, cv>
//     {
//         return gem::Dimension<T1, cv, cv, cv> {cv};
//     }
// };

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
    apply(const gem::Dimension<T2, cv, max_cv2, min_cv2> xs)
        -> gem::Dimension<T1, cv, max_cv1, min_cv1>
    {
        return gem::Dimension<T1, cv, max_cv1, min_cv1> {cv};
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
        BOOST_HANA_RUNTIME_CHECK_MSG(d.value() == cv1,
                                     "Runtime value and compile time "
                                     "value differ.");
        return gem::Dimension<T1, cv1, cv1, cv1> {};
    }
};

// No runtime to compile time conversion.

} // namespace boost::hana

#endif // DIMENSIONS_TO_HPP_INCLUDED