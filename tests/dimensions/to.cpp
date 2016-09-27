#include <cassert>
#include <boost/hana/assert.hpp>
#include <boost/hana/core.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    {
        // Compile time to compile time
        auto d = Dim(integral_c<int, 2>);
        boost::hana::to<
            gem::dimension_tag<unsigned long long, 2, 2>
        >(d);
    }

    {
        // Compile time to runtime
        auto d = Dim(integral_c<int, 2>);
        boost::hana::to<
            gem::dimension_tag<unsigned long long, 4, 0>
        >(d);
    }

    {
        // Runtime time to compile time
        auto d = Dim(2);
        boost::hana::to<
            gem::dimension_tag<unsigned long long, 2, 2>
        >(d);
    }

    {
        // Runtime time to runtime
        auto d = Dim(2);
        boost::hana::to<
            gem::dimension_tag<unsigned long long, 4, 0>
        >(d);
    }


}