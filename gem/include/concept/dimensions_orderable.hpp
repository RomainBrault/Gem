#ifndef DIMENSION_ORDERABLE_HPP_INCLUDED
#define DIMENSION_ORDERABLE_HPP_INCLUDED

#include <boost/hana/less.hpp>
#include <boost/hana/less_equal.hpp>
#include <boost/hana/greater.hpp>
#include <boost/hana/greater_equal.hpp>

namespace boost::hana {

template<typename T1, T1 cv_max1, T1 cv_min1,
         typename T2, T2 cv_max2, T2 cv_min2>
struct less_impl<gem::dimension_tag<T1, cv_max1, cv_min1>,
                  gem::dimension_tag<T2, cv_max2, cv_min2>>
{
    static constexpr decltype(auto) apply(const auto& d1, const auto& d2)
    {
        return d1.value() < d2.value();
    }
};

template<typename T1, T1 cv_max1, T1 cv_min1,
         typename T2, T2 cv_max2, T2 cv_min2>
struct less_equal_impl<gem::dimension_tag<T1, cv_max1, cv_min1>,
                  gem::dimension_tag<T2, cv_max2, cv_min2>>
{
    static constexpr decltype(auto) apply(const auto& d1, const auto& d2)
    {
        return d1.value() <= d2.value();
    }
};

template<typename T1, T1 cv_max1, T1 cv_min1,
         typename T2, T2 cv_max2, T2 cv_min2>
struct greater_impl<gem::dimension_tag<T1, cv_max1, cv_min1>,
                  gem::dimension_tag<T2, cv_max2, cv_min2>>
{
    static constexpr decltype(auto) apply(const auto& d1, const auto& d2)
    {
        return d1.value() > d2.value();
    }
};

template<typename T1, T1 cv_max1, T1 cv_min1,
         typename T2, T2 cv_max2, T2 cv_min2>
struct greater_equal_impl<gem::dimension_tag<T1, cv_max1, cv_min1>,
                  gem::dimension_tag<T2, cv_max2, cv_min2>>
{
    static constexpr decltype(auto) apply(const auto& d1, const auto& d2)
    {
        return d1.value() >= d2.value();
    }
};

} // namespace boost::hana

namespace gem {

BOOST_HANA_CONSTEXPR_LAMBDA auto le =
    boost::hana::infix([](const auto& x, const auto& y) {
        // this could be a more efficient implementation
        return boost::hana::less(x, y);
    });

BOOST_HANA_CONSTEXPR_LAMBDA auto leq =
    boost::hana::infix([](const auto& x, const auto& y) {
        // this could be a more efficient implementation
        return boost::hana::less_equal(x, y);
    });

BOOST_HANA_CONSTEXPR_LAMBDA auto ge =
    boost::hana::infix([](const auto& x, const auto& y) {
        // this could be a more efficient implementation
        return boost::hana::greater(x, y);
    });

BOOST_HANA_CONSTEXPR_LAMBDA auto geq =
    boost::hana::infix([](const auto& x, const auto& y) {
        // this could be a more efficient implementation
        return boost::hana::greater_equal(x, y);
    });

} // namespace gem

#endif // DIMENSION_ORDERABLE_HPP_INCLUDED