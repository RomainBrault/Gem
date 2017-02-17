#include <cstdlib>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{
    {
        [[maybe_unused]] Dimension d {2};
    }

    {
        [[maybe_unused]] Dimension d {2u};
    }

    {
        [[maybe_unused]] Dimension d {2_c};
    }

    {
        [[maybe_unused]] Dimension d {2_u};
    }

    {
        [[maybe_unused]] Dimension d = {2};
    }

    {
        [[maybe_unused]] Dimension d = {2u};
    }

    {
        [[maybe_unused]] Dimension d = {2_c};
    }

    {
        [[maybe_unused]] Dimension d = {2_u};
    }

    {
        [[maybe_unused]] Dimension d1 {2_u};
        [[maybe_unused]] Dimension d2 {d1};
    }

    {
        [[maybe_unused]] Dimension d1 = {2_u};
        [[maybe_unused]] Dimension d2 = {d1};
    }

    {
        [[maybe_unused]] Dimension d1 {2u};
        [[maybe_unused]] Dimension d2 {d1};
    }

    {
        [[maybe_unused]] Dimension d1 = {2u};
        [[maybe_unused]] Dimension d2 = {d1};
    }

    return EXIT_SUCCESS;
}
