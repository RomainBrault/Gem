#ifndef DIMENSIONS_GROUP_HPP_INCLUDED
#define DIMENSIONS_GROUP_HPP_INCLUDED

#include <limits>

#include <boost/hana/zero.hpp>
#include <boost/hana/plus.hpp>
#include <boost/hana/less.hpp>

#include <gem/concept/dimensions.hpp>

namespace boost::hana {

template<typename T>
static constexpr
auto safe_sub(const T & v1, const T & v2)
{
    return v1 >= v2 ? v1 - v2 : 0;
}

GemDimensionPair {T1, cv1, max1, min1, T2, cv2, max2, min2}
struct minus_impl<gem::Dimension<T1, cv1, max1, min1>,
                  gem::Dimension<T2, cv2, max2, min2>>
{
private:
    using ctype = typename boost::hana::common<T1, T2>::type;

public:
    static constexpr auto
    apply(const gem::Dimension<T1, cv1, max1, min1>& d1,
          const gem::Dimension<T2, cv2, max2, min2>& d2)
    {
        BOOST_HANA_RUNTIME_CHECK_MSG(d1.value() >= d2.value(),
                                     "Dimension underflow...");
        return gem::Dimension<ctype, safe_sub<ctype>(cv1, cv2),
                                     safe_sub<ctype>(max1, min2),
                                     safe_sub<ctype>(min1, max2)> {d1.value() -
                                                                   d2.value()};
    }
};

template<typename T1, T1 cv1, typename T2, T2 cv2>
struct minus_impl<gem::Dimension<T1, cv1, cv1, cv1>,
                  gem::Dimension<T2, cv2, cv2, cv2>>
{
private:
    using ctype = typename boost::hana::common<T1, T2>::type;

public:
    static constexpr auto
    apply(const gem::Dimension<T1, cv1, cv1, cv1> &,
          const gem::Dimension<T2, cv2, cv2, cv2> &)
    {
        constexpr auto c = integral_c<ctype, cv1>;
        constexpr auto m = integral_c<ctype, cv2>;
        BOOST_HANA_CONSTANT_CHECK_MSG(c >= m, "Dimension underflow...");
        constexpr ctype s = static_cast<ctype>(cv1) -
                            static_cast<ctype>(cv2);
        return gem::Dimension<ctype, s, s, s> {};
    }
};

} // namespace boost::hana

namespace gem {

template <typename T1, T1 cv1, T1 cv_max1, T1 cv_min1,
          typename T2, T2 cv2, T2 cv_max2, T2 cv_min2>
constexpr inline auto
operator-(const gem::Dimension<T1, cv1, cv_max1, cv_min1> & d1,
          const gem::Dimension<T2, cv2, cv_max2, cv_min2> & d2)
{
    return boost::hana::minus(d1, d2);
}

} // namespace gem

#endif // DIMENSIONS_GROUP_HPP_INCLUDED