#ifndef DIMENSIONS_COMPARABLE_HPP_INCLUDED
#define DIMENSIONS_COMPARABLE_HPP_INCLUDED

#include <boost/hana/equal.hpp>
#include <boost/hana/not_equal.hpp>

#include <gem/fwd/dimensions.hpp>

namespace boost::hana {

GemDimensionPair {T1, cv1, max1, min1, T2, cv2, max2, min2}
struct equal_impl<gem::Dimension<T1, cv1, max1, min1>,
                  gem::Dimension<T2, cv2, max2, min2>>
{
    static constexpr auto
    apply(const gem::Dimension<T1, cv1, max1, min1>& d1,
          const gem::Dimension<T2, cv2, max2, min2>& d2)
    {
        return d1.value() == d2.value();
    }
};

GemDimensionPair {T1, cv1, max1, min1, T2, cv2, max2, min2}
struct not_equal_impl<gem::Dimension<T1, cv1, max1, min1>,
                      gem::Dimension<T2, cv2, max2, min2>>
{
    static constexpr auto
    apply(const gem::Dimension<T1, cv1, max1, min1>& d1,
          const gem::Dimension<T2, cv2, max2, min2>& d2)
    {
        return d1.value() != d2.value();
    }
};

}

namespace gem {

BOOST_HANA_CONSTEXPR_LAMBDA auto eq =
    boost::hana::infix([](const auto& x, const auto& y) {
        // this could be a more efficient implementation
        return boost::hana::equal(x, y);
    });

BOOST_HANA_CONSTEXPR_LAMBDA auto neq =
    boost::hana::infix([](const auto& x, const auto& y) {
        // this could be a more efficient implementation
        return boost::hana::not_equal(x, y);
    });

} // namespace gem

#endif // DIMENSIONS_COMPARABLE_HPP_INCLUDED