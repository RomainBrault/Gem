#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    {
        auto d1 = Dim(2);
        auto d2 = 2u;
        auto d3 = 3u;
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d1 ^eq^ d2);
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(d1 ^neq^ d3);
    }

    {
        auto d1 = Dim(2_u);
        auto d2 = 2u;
        auto d3 = 3u;
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d1 ^eq^ d2);
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(d1 ^neq^ d3);
    }

    {
        auto d1 = Dim(2);
        auto d2 = 2_u;
        auto d3 = 3_u;
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d1 ^eq^ d2);
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(d1 ^neq^ d3);
    }

    {
        auto d1 = Dim(2_u);
        auto d2 = 2_u;
        auto d3 = 3_u;
        BOOST_HANA_CONSTANT_CHECK(equal(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(d1 ^eq^ d2);
        BOOST_HANA_CONSTANT_CHECK(not_equal(d1, d3));
        BOOST_HANA_CONSTANT_CHECK(d1 ^neq^ d3);
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
        auto d2 = Dim(3_u);
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
        auto d2 = Dim(2_u);
        auto d3 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(equal(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(equal(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d1, d3));
        BOOST_HANA_RUNTIME_CHECK(not_equal(d2, d3));
    }

    {
        auto d1 = Dim(2_u);
        auto d2 = Dim(2_c);
        auto d3 = Dim(3_u);
        BOOST_HANA_CONSTANT_CHECK(equal(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(equal(d2, d1));
        BOOST_HANA_CONSTANT_CHECK(not_equal(d1, d3));
        BOOST_HANA_CONSTANT_CHECK(not_equal(d2, d3));
    }
}