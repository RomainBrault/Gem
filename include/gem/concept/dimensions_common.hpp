#ifndef DIMENSIONS_COMMON_HPP_INCLUDED
#define DIMENSIONS_COMMON_HPP_INCLUDED

#include <type_traits>
#include <algorithm>

#include <boost/hana/core/common.hpp>

#include <gem/concept/dimensions.hpp>

namespace boost::hana {

GemCommonDimensionPair {T1, cv1, max1, min1, T2, cv2, max2, min2}
struct common<gem::Dimension<T1, cv1, max1, min1>,
              gem::Dimension<T2, cv2, max2, min2>>
{
private:
    using stype = typename boost::hana::common<T1, T2>::type;

public:
    using type = gem::Dimension<stype, cv1 / 2 + cv2 / 2,
                                std::max<stype>(max1, max2),
                                std::min<stype>(min1, min2)>;
};

GemCommonIntegralDimensionPair {T1, T2, cv, max, min}
struct common<T1, gem::Dimension<T2, cv, max, min>>
{
    using type = typename boost::hana::common<T1, T2>::type;
};

GemCommonDimensionIntegralPair {T1, cv, max, min, T2}
struct common<gem::Dimension<T1, cv, max, min>, T2>
{
    using type = typename boost::hana::common<T1, T2>::type;
};

GemCommonIntegralDimensionPair {T1, T2, cv, max, min}
struct common<boost::hana::integral_constant_tag<T1>,
              gem::Dimension<T2, cv, max, min>>
{
private:
    using stype = typename boost::hana::common<T1, T2>::type;

public:
    using type = std::conditional_t<(max == min),
                                    boost::hana::integral_constant_tag<stype>,
                                    stype>;

};

GemCommonDimensionIntegralPair {T1, cv, max, min, T2}
struct common<gem::Dimension<T1, cv, max, min>,
              boost::hana::integral_constant_tag<T2>>
{
private:
    using stype = typename boost::hana::common<T1, T2>::type;

public:
    using type = std::conditional_t<(max == min),
                                    boost::hana::integral_constant_tag<stype>,
                                    stype>;
};

} // namespace boost::hana

#endif  // DIMENSIONS_COMMON_HPP_INCLUDED
