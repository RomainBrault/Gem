#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    {
        auto d1 = Dim(2);
        auto d2 = 3u;
        BOOST_HANA_RUNTIME_CHECK(less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d2 ^ge^ d1);
        BOOST_HANA_RUNTIME_CHECK(d1 ^leq^ d1);
        BOOST_HANA_RUNTIME_CHECK(d2 ^geq^ d2);
    }

    {
        auto d1 = 2u;
        auto d2 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d2 ^ge^ d1);
        BOOST_HANA_RUNTIME_CHECK(d1 ^leq^ d1);
        BOOST_HANA_RUNTIME_CHECK(d2 ^geq^ d2);
    }

    {
        auto d1 = Dim(2_u);
        auto d2 = 3u;
        BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK (d2 ^ge^ d1);
        BOOST_HANA_CONSTANT_CHECK(d1 ^leq^ d1);
        BOOST_HANA_RUNTIME_CHECK (d2 ^geq^ d2);
    }

    {
        auto d1 = 2u;
        auto d2 = Dim(3_u);
        BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK (d2 ^ge^ d1);
        BOOST_HANA_RUNTIME_CHECK (d1 ^leq^ d1);
        BOOST_HANA_CONSTANT_CHECK(d2 ^geq^ d2);
    }

    {
        auto d1 = 2_u;
        auto d2 = Dim(3_u);
        BOOST_HANA_CONSTANT_CHECK(less(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(d2 ^ge^ d1);
        BOOST_HANA_CONSTANT_CHECK(d1 ^leq^ d1);
        BOOST_HANA_CONSTANT_CHECK(d2 ^geq^ d2);
    }

    {
        auto d1 = Dim(2);
        auto d2 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(d2 ^ge^ d1);
        BOOST_HANA_RUNTIME_CHECK(d1 ^leq^ d1);
        BOOST_HANA_RUNTIME_CHECK(d2 ^geq^ d2);
    }

    {
        auto d1 = Dim(2);
        auto d2 = Dim(3_u);
        BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK (d2 ^ge^ d1);
        BOOST_HANA_RUNTIME_CHECK (d1 ^leq^ d1);
        BOOST_HANA_CONSTANT_CHECK(d2 ^geq^ d2);
    }

    {
        auto d1 = Dim(2_c);
        auto d2 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK (d2 ^ge^ d1);
        BOOST_HANA_CONSTANT_CHECK(d1 ^leq^ d1);
        BOOST_HANA_RUNTIME_CHECK (d2 ^geq^ d2);
    }

    {
        auto d1 = Dim(2_c);
        auto d2 = Dim(3_u);
        BOOST_HANA_CONSTANT_CHECK(less(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(d2 ^ge^ d1);
        BOOST_HANA_CONSTANT_CHECK(d1 ^leq^ d1);
        BOOST_HANA_CONSTANT_CHECK(d2 ^geq^ d2);
    }
}