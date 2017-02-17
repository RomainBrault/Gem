#include <cstdlib>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    // {
    //     Dimension d1 {2};
    //     auto d2 = 3u;
    //     BOOST_HANA_RUNTIME_CHECK(less(d1, d2));
    //     BOOST_HANA_RUNTIME_CHECK(d2 > d1);
    //     BOOST_HANA_RUNTIME_CHECK(d1 <= d1);
    //     BOOST_HANA_RUNTIME_CHECK(d2 <= d2);
    // }

    // {
    //     auto d1 = 2u;
    //     Dimension d2 {3};
    //     BOOST_HANA_RUNTIME_CHECK(less(d1, d2));
    //     BOOST_HANA_RUNTIME_CHECK(d2 > d1);
    //     BOOST_HANA_RUNTIME_CHECK(d1 <= d1);
    //     BOOST_HANA_RUNTIME_CHECK(d2 >= d2);
    // }

    // {
    //     Dimension d1 {2_u};
    //     auto d2 = 3u;
    //     BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
    //     BOOST_HANA_RUNTIME_CHECK (d2 > d1);
    //     BOOST_HANA_CONSTANT_CHECK(d1 <= d1);
    //     BOOST_HANA_RUNTIME_CHECK (d2 >= d2);
    // }

    // {
    //     auto d1 = 2u;
    //     Dimension d2 {3_u};
    //     BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
    //     BOOST_HANA_RUNTIME_CHECK (d2 > d1);
    //     BOOST_HANA_RUNTIME_CHECK (d1 <= d1);
    //     BOOST_HANA_CONSTANT_CHECK(d2 >= d2);
    // }

    // {
    //     auto d1 = 2_u;
    //     Dimension d2 {3_u};
    //     BOOST_HANA_CONSTANT_CHECK(less(d1, d2));
    //     BOOST_HANA_CONSTANT_CHECK(d2 > d1);
    //     BOOST_HANA_CONSTANT_CHECK(d1 <= d1);
    //     BOOST_HANA_CONSTANT_CHECK(d2 >= d2);
    // }

    // {
    //     Dimension d1 {2};
    //     Dimension d2 {3};
    //     BOOST_HANA_RUNTIME_CHECK(less(d1, d2));
    //     BOOST_HANA_RUNTIME_CHECK(d2 > d1);
    //     BOOST_HANA_RUNTIME_CHECK(d1 <= d1);
    //     BOOST_HANA_RUNTIME_CHECK(d2 >= d2);
    // }

    // {
    //     Dimension d1 {2};
    //     Dimension d2 {3_u};
    //     BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
    //     BOOST_HANA_RUNTIME_CHECK (d2 > d1);
    //     BOOST_HANA_RUNTIME_CHECK (d1 <= d1);
    //     BOOST_HANA_CONSTANT_CHECK(d2 >= d2);
    // }

    // {
    //     Dimension d1 {2_c};
    //     Dimension d2 {3};
    //     BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
    //     BOOST_HANA_RUNTIME_CHECK (d2 > d1);
    //     BOOST_HANA_CONSTANT_CHECK(d1 <= d1);
    //     BOOST_HANA_RUNTIME_CHECK (d2 >= d2);
    // }

    // {
    //     Dimension d1 {2_c};
    //     Dimension d2 {3_u};
    //     // BOOST_HANA_CONSTANT_CHECK(less(d1, d2));
    //     BOOST_HANA_CONSTANT_CHECK(d2 > d1);
    //     BOOST_HANA_CONSTANT_CHECK(d1 <= d1);
    //     BOOST_HANA_CONSTANT_CHECK(d2 >= d2);
    // }

    return EXIT_SUCCESS;
}
