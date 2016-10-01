#ifndef DIMENSIONS_COMPARABLE_HPP_INCLUDED
#define DIMENSIONS_COMPARABLE_HPP_INCLUDED

#include <boost/hana/equal.hpp>
#include <boost/hana/not_equal.hpp>

namespace boost::hana {

template<typename T1, T1 cv_max1, T1 cv_min1,
         typename T2, T2 cv_max2, T2 cv_min2>
struct equal_impl<gem::dimension_tag<T1, cv_max1, cv_min1>,
                  gem::dimension_tag<T2, cv_max2, cv_min2>>
{
    static constexpr auto apply(const auto& d1, const auto& d2)
    {
        return d1.value() == d2.value();
    }
};

template<typename T1, T1 cv_max1, T1 cv_min1,
         typename T2, T2 cv_max2, T2 cv_min2>
struct not_equal_impl<gem::dimension_tag<T1, cv_max1, cv_min1>,
                  gem::dimension_tag<T2, cv_max2, cv_min2>>
{
    static constexpr auto apply(const auto& d1, const auto& d2)
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