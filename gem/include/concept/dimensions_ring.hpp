#ifndef DIMENSIONS_RING_HPP_INCLUDED
#define DIMENSIONS_RING_HPP_INCLUDED

#include <limits>

#include <boost/hana/one.hpp>
#include <boost/hana/mult.hpp>

#include <gem/concept/dimensions.hpp>

namespace boost::hana {

template<typename T>
static constexpr
auto safe_mult(const T & v1, const T & v2)
{
    return v1 < std::numeric_limits<T>::max() / v2 ?
        v1 * v2 :
        std::numeric_limits<T>::max();
}

GemValidDimension {T, cv, max, min}
struct one_impl<gem::Dimension<T, cv, max, min>>
{
    static constexpr auto apply(void)
        -> gem::Dimension<T, 1, 1, 1>
    {
        return {};
    }
};

GemDimensionPair {T1, cv1, max1, min1, T2, cv2, max2, min2}
struct mult_impl<gem::Dimension<T1, cv1, max1, min1>,
                 gem::Dimension<T2, cv2, max2, min2>>
{

    using ctype = typename boost::hana::common<T1, T2>::type;

    static constexpr auto
    apply(const gem::Dimension<T1, cv1, max1, min1>& d1,
          const gem::Dimension<T2, cv2, max2, min2>& d2)
    {
        BOOST_HANA_RUNTIME_CHECK(boost::hana::to<ctype>(d1.value()) <
                                 std::numeric_limits<ctype>::max() /
                                 boost::hana::to<ctype>(d2.value()),
                                 "Dimension overflow...");
        return gem::Dimension<ctype, safe_mult<ctype>(cv1, cv2),
                                     safe_mult<ctype>(max1, max2),
                                     safe_mult<ctype>(min1, min2)> {d1.value() *
                                                                    d2.value()};
    }
};

template<typename T1, T1 cv1, typename T2, T2 cv2>
struct mult_impl<gem::Dimension<T1, cv1, cv1, cv1>,
                 gem::Dimension<T2, cv2, cv2, cv2>>
{
private:
    using ctype = typename boost::hana::common<T1, T2>::type;

public:
    static constexpr auto
    apply(const gem::Dimension<T1, cv1, cv1, cv1> & d1,
          const gem::Dimension<T2, cv2, cv2, cv2> & d2)
    {
        constexpr auto c =
            integral_c<ctype, cv1>;
        constexpr auto m =
            integral_c<ctype, std::numeric_limits<ctype>::max() / cv2>;
        BOOST_HANA_CONSTANT_CHECK_MSG(c < m, "Dimension overflow...");
        constexpr auto s = static_cast<ctype>(cv1) *
                           static_cast<ctype>(cv2);
        return gem::Dimension<ctype, s, s, s> {};
    }
};

} // namespace boost::hana

namespace gem {

template <typename T1, T1 cv1, T1 cv_max1, T1 cv_min1,
          typename T2, T2 cv2, T2 cv_max2, T2 cv_min2>
constexpr inline auto
operator*(const gem::Dimension<T1, cv1, cv_max1, cv_min1> & d1,
          const gem::Dimension<T2, cv2, cv_max2, cv_min2> & d2)
{
    return boost::hana::mult(d1, d2);
}

} // namespace gem

#endif // DIMENSIONS_RING_HPP_INCLUDED