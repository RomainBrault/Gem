#ifndef DIMENSIONS_MONOID_HPP_INCLUDED
#define DIMENSIONS_MONOID_HPP_INCLUDED

#include <limits>

#include <boost/hana/zero.hpp>
#include <boost/hana/plus.hpp>
#include <boost/hana/less.hpp>

#include <gem/concept/dimensions.hpp>

namespace boost::hana {

template<typename T>
static constexpr
auto safe_add(const T & v1, const T & v2)
{
    return v1 < std::numeric_limits<T>::max() - v2 ?
        v1 + v2 :
        std::numeric_limits<T>::max();
}

template<typename T, T cv_max, T cv_min>
struct zero_impl<gem::dimension_tag<T, cv_max, cv_min>>
{
    static constexpr auto apply(void)
        -> gem::Dimension<std::make_unsigned_t<T>, 0, 0, 0>
    {
        return {};
    }
};

template<typename T, T cv1, T cv2>
struct plus_impl<gem::dimension_tag<T, cv1, cv1>,
                 gem::dimension_tag<T, cv2, cv2>>
{
    static constexpr auto apply(const gem::Dimension<T, cv1, cv1, cv1> & d1,
                                const gem::Dimension<T, cv2, cv2, cv2> & d2)
        -> gem::Dimension<T, cv1 + cv2, cv1 + cv2, cv1 + cv2>
    {
        constexpr auto c = integral_c<T, cv1>;
        constexpr auto m = integral_c<T, std::numeric_limits<T>::max() - cv2>;
        BOOST_HANA_CONSTANT_CHECK_MSG(c < m, "Dimension overflow...");
        constexpr auto s = cv1 + cv2;
        return gem::Dimension<T, s, s, s> {};
    }
};

template<typename T, T cv_max1, T cv_min1, T cv_max2, T cv_min2>
struct plus_impl<gem::dimension_tag<T, cv_max1, cv_min1>,
                 gem::dimension_tag<T, cv_max2, cv_min2>>
{
    template<T cv1, T cv2>
    static constexpr auto apply(const gem::Dimension<T, cv1,
                                                        cv_max1, cv_min1> & d1,
                                const gem::Dimension<T, cv2,
                                                        cv_max2, cv_min2> & d2)
        -> gem::Dimension<T, safe_add(cv1, cv2),
                             safe_add(cv_max1, cv_max2),
                             safe_add(cv_min1, cv_min2)>
    {
        return gem::Dimension<T, safe_add(cv1, cv2),
                                 safe_add(cv_max1, cv_max2),
                                 safe_add(cv_min1, cv_min2)> {d1.value() +
                                                              d2.value()};
    }
};

} // namespace boost::hana

namespace gem {

template <typename T1, T1 cv1, T1 cv_max1, T1 cv_min1,
          typename T2, T2 cv2, T2 cv_max2, T2 cv_min2>
constexpr inline auto
operator+(const gem::Dimension<T1, cv1, cv_max1, cv_min1> & d1,
          const gem::Dimension<T2, cv2, cv_max2, cv_min2> & d2)
{
    return boost::hana::plus(d1, d2);
}

} // namespace gem

#endif // DIMENSIONS_MONOID_HPP_INCLUDED