#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{
    // {
    //     auto d1 = Dim(2);
    //     auto d2 = Dim(2);

    //     auto d3 = Dim(4);
    //     auto d4 = Dim(3);
    //     auto d5 = Dim(5);

    //     auto d6 = Dim(4_c);
    //     auto d7 = Dim(3_c);
    //     auto d8 = Dim(5_c);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 == 4);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 == d3);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 != d4);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 <= d5);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 >= d4);

    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 == 4);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 == d6);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 != d7);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 <= d8);
    //     BOOST_HANA_RUNTIME_CHECK(d1 * d2 >= d7);
    // }

    // {
    //     auto d1 = Dim(2_c);
    //     auto d2 = Dim(2_c);
    //     BOOST_HANA_RUNTIME_CHECK (d1 * d2 == 4);
    //     // BOOST_HANA_CONSTANT_CHECK(d1 * d2 == 4_c);
    // }

}