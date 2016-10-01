#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    {
        auto d1 = Dim(2);
        auto d2 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK(less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK(greater(d2, d1));
        BOOST_HANA_RUNTIME_CHECK(less_equal(d1, d1));
        BOOST_HANA_RUNTIME_CHECK(greater_equal(d2, d2));
    }

    {
        auto d1 = Dim(2);
        auto d2 = Dim(3_c);
        BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK (greater(d2, d1));
        BOOST_HANA_RUNTIME_CHECK (less_equal(d1, d1));
        BOOST_HANA_CONSTANT_CHECK(greater_equal(d2, d2));
    }

    {
        auto d1 = Dim(2_c);
        auto d2 = Dim(3);
        BOOST_HANA_RUNTIME_CHECK (less(d1, d2));
        BOOST_HANA_RUNTIME_CHECK (greater(d2, d1));
        BOOST_HANA_CONSTANT_CHECK(less_equal(d1, d1));
        BOOST_HANA_RUNTIME_CHECK (greater_equal(d2, d2));
    }

    {
        auto d1 = Dim(2_c);
        auto d2 = Dim(3_c);
        BOOST_HANA_CONSTANT_CHECK(less(d1, d2));
        BOOST_HANA_CONSTANT_CHECK(greater(d2, d1));
        BOOST_HANA_CONSTANT_CHECK(less_equal(d1, d1));
        BOOST_HANA_CONSTANT_CHECK(greater_equal(d2, d2));
    }
}