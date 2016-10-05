#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    {
        auto d1 = Dim(2);
        BOOST_HANA_RUNTIME_CHECK(equal(d1, 2));
        BOOST_HANA_RUNTIME_CHECK(d1 ^eq^ 2);
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, 3));
        BOOST_HANA_RUNTIME_CHECK(d1 ^neq^ 3);
    }

    {
        // auto d1 = Dim(2_c);
        // BOOST_HANA_RUNTIME_CHECK(equal(d1, 2));
        // BOOST_HANA_RUNTIME_CHECK(d1 ^eq^ 2);
        // BOOST_HANA_RUNTIME_CHECK(not_equal(d1, 3));
        // BOOST_HANA_RUNTIME_CHECK(d1 ^neq^ 3);
    }

    {
        auto d1 = Dim(2);
        auto d2 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d1));
        BOOST_HANA_RUNTIME_CHECK(d1 ^eq^ d1);
        BOOST_HANA_RUNTIME_CHECK(d1 ^neq^ d2);
    }

    {
        auto d1 = Dim(2_c);
        auto d2 = Dim(3_c);
        BOOST_HANA_CONSTANT_CHECK(equal(d1, d1));
        BOOST_HANA_CONSTANT_CHECK(d1 ^neq^ d2);
    }

    {
        auto d1 = Dim(2);
        auto d2 = Dim(2);
        auto d3 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(equal(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d2, d3));
    }

    {
        auto d1 = Dim(2_c);
        auto d2 = Dim(2);
        auto d3 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(equal(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d2, d3));
    }

    {
        auto d1 = Dim(2);
        auto d2 = Dim(2_c);
        auto d3 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(equal(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d2, d3));
    }

    {
        auto d1 = Dim(2_c);
        auto d2 = Dim(2_c);
        auto d3 = Dim(3_c);
        BOOST_HANA_CONSTANT_CHECK(equal(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(equal(d2, d1));
        BOOST_HANA_CONSTANT_CHECK(not_equal(d1, d3));
        BOOST_HANA_CONSTANT_CHECK(not_equal(d2, d3));
    }
}