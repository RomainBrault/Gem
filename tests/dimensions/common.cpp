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

        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }


    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<unsigned int,
            decltype(d)>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<unsigned int,
            decltype(d)>::value);
    }

    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<unsigned int,
            decltype(d)>::value);
    }

    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        auto d = Dim(2u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        auto d = Dim(2_u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }

    {
        auto d = Dim(2_c);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }

    {
        auto d = Dim(2);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }

    {
        auto d = Dim(2u);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }
}