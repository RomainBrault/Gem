#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{
    {
        auto d1 = Dim(3);
        auto d2 = Dim(1);

        auto d3 = Dim(2);
        auto d4 = Dim(1);
        auto d5 = Dim(5);

        auto d6 = Dim(2_c);
        auto d7 = Dim(1_c);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ d3);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^le^ d5);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^geq^ (d4 - d4));

        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ 2_u);

        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^leq^ d6);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^ge^ d7);
    }

    {
        auto d1 = Dim(3_u);
        auto d2 = Dim(1_c);

        auto d3 = Dim(2);
        auto d4 = Dim(1);
        auto d5 = Dim(5);

        auto d6 = Dim(2_c);
        auto d7 = Dim(1_c);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ d3);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^le^ d5);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^geq^ (d4 - d4));

        BOOST_HANA_RUNTIME_CHECK ((d1 - d2) ^eq^ 2u);
        BOOST_HANA_CONSTANT_CHECK((d1 - d2) ^eq^ 2_u);

        BOOST_HANA_CONSTANT_CHECK((d1 - d2) ^leq^ d6);
        BOOST_HANA_CONSTANT_CHECK((d1 - d2) ^ge^ d7);
    }

    {
        auto d1 = Dim(3_u);
        auto d2 = Dim(1);

        auto d3 = Dim(2);
        auto d4 = Dim(1);
        auto d5 = Dim(5);

        auto d6 = Dim(2_c);
        auto d7 = Dim(1_c);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ d3);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^le^ d5);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^geq^ (d4 - d4));

        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ 2_u);

        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^leq^ d6);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^ge^ d7);
    }

    {
        auto d1 = Dim(3);
        auto d2 = Dim(1_c);

        auto d3 = Dim(2);
        auto d4 = Dim(1);
        auto d5 = Dim(5);

        auto d6 = Dim(2_c);
        auto d7 = Dim(1_c);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ d3);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^le^ d5);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^geq^ (d4 - d4));

        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^eq^ 2_u);

        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^leq^ d6);
        BOOST_HANA_RUNTIME_CHECK((d1 - d2) ^ge^ d7);
    }

}