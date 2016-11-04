#include <cassert>
#include <boost/hana/assert.hpp>
#include <boost/hana/core.hpp>

#include <gem/gem.hpp>

#include <limits>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{
    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            decltype(d)>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

}