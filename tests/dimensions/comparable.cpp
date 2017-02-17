#include <cstdlib>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{
    {
        Dimension d1 {2};
        auto d2 = 2u;
        auto d3 = 3u;
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d1 == d2);
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(d1 != d3);
    }

    {
        Dimension d1 {2_u};
        auto d2 = 2u;
        auto d3 = 3u;
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d1 == d2);
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(d1 != d3);
    }

    {
        Dimension d1 {2};
        auto d2 = 2_u;
        auto d3 = 3_u;
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d1 == d2);
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(d1 != d3);
    }

    {
        Dimension d1 {2_u};
        auto d2 = 2_u;
        auto d3 = 3_u;
        BOOST_HANA_CONSTANT_CHECK(equal(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(d1 == d2);
        BOOST_HANA_CONSTANT_CHECK(not_equal(d1, d3));
        BOOST_HANA_CONSTANT_CHECK(d1 != d3);
    }

    {
        Dimension d1 {2};
        Dimension d2 {3};
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d1));
        BOOST_HANA_RUNTIME_CHECK(d1 == d1);
        BOOST_HANA_RUNTIME_CHECK(d1 != d2);
    }

    {
        Dimension d1 {2_c};
        Dimension d2 {3_u};
        BOOST_HANA_CONSTANT_CHECK(equal(d1, d1));
        BOOST_HANA_CONSTANT_CHECK(d1 != d2);
    }

    {
        Dimension d1 {2};
        Dimension d2 {2};
        Dimension d3 {3};
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(equal(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d2, d3));
    }

    {
        Dimension d1 {2_c};
        Dimension d2 {2};
        Dimension d3 {3};
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(equal(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d2, d3));
    }

    {
        Dimension d1 {2};
        Dimension d2 {2_u};
        Dimension d3 {3};
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(equal(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d2, d3));
    }

    {
        Dimension d1 {2_u};
        Dimension d2 {2_c};
        Dimension d3 {3_u};
        BOOST_HANA_CONSTANT_CHECK(equal(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(equal(d2, d1));
        // BOOST_HANA_CONSTANT_CHECK(not_equal(d1, d3));
        // BOOST_HANA_CONSTANT_CHECK(not_equal(d2, d3));
    }

    return EXIT_SUCCESS;
}
