#include <cstdlib>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{
    {

        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }


    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<unsigned int,
            decltype(d)>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<unsigned int,
            decltype(d)>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<unsigned int,
            decltype(d)>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        Dimension d {2u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<decltype(d),
            integral_constant<unsigned int, 2>>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }

    {
        Dimension d {2u};
        BOOST_HANA_CONSTEXPR_CHECK(has_common<
            integral_constant<unsigned int, 2>,
            decltype(d)>::value);
    }

    return EXIT_SUCCESS;
}
