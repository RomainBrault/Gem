#include <cstdlib>
#include <boost/hana/assert.hpp>
#include <boost/hana/integral_constant.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{
    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            unsigned int>::value);
    }

    {
        Dimension d {2};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            decltype(d)>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 4, 0>>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            Dimension<unsigned int, 2, 2, 2>>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            integral_constant_tag<unsigned int>>::value);
    }

    {
        Dimension d {2_c};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            CompileTimeDimensionTag<unsigned int>>::value);
    }

    {
        Dimension d {2u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            RuntimeDimensionTag<unsigned int>>::value);
    }

    {
        Dimension d {2_u};
        BOOST_HANA_CONSTEXPR_CHECK(is_convertible<decltype(d),
            RuntimeDimensionTag<unsigned int>>::value);
    }

    return EXIT_SUCCESS;
}
