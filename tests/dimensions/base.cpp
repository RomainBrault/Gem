#include <cassert>
#include <boost/hana/assert.hpp>
#include <iostream>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    /* CHECK DIMENSION */
    {
        auto m = MatrixXd(1_u, 1_u);
        BOOST_HANA_CONSTANT_CHECK(m.order ^eq^ 2_u);
    }

    {
        auto m = MatrixXd(1, 2);

        BOOST_HANA_RUNTIME_CHECK(m.dim[GEM_START_IDX      ] ^eq^ 1u);
        BOOST_HANA_RUNTIME_CHECK(m.dim[GEM_START_IDX + 1_u] ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK(m.cols() ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK(m.cols() ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK(m.rows() ^eq^ 1u);
        BOOST_HANA_RUNTIME_CHECK(m.rows() ^eq^ 1_u);
        BOOST_HANA_RUNTIME_CHECK(m.size() ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK(m.size() ^eq^ 2_u);
    }

    {
        auto m = MatrixXd(1_u, 2);

        BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX      ] ^eq^ 1_u);
        BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX + 1_u] ^eq^ 2_u);
        BOOST_HANA_CONSTANT_CHECK(m.rows() ^eq^ 1_u);
        BOOST_HANA_RUNTIME_CHECK (m.rows() ^eq^ 1u);
        BOOST_HANA_RUNTIME_CHECK (m.cols() ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK (m.cols() ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK (m.size() ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK (m.size() ^eq^ 2u);
    }

    {
        auto m = MatrixXd(1, 2_u);

        BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX      ] ^eq^ 1_u);
        BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX + 1_u] ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK (m.rows() ^eq^ 1_u);
        BOOST_HANA_RUNTIME_CHECK (m.rows() ^eq^ 1u);
        BOOST_HANA_CONSTANT_CHECK(m.cols() ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK (m.cols() ^eq^ 2u);
        BOOST_HANA_RUNTIME_CHECK (m.size() ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK (m.size() ^eq^ 2u);
    }


    {
        auto m = MatrixXd(1_u, 2_u);

        BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX      ] ^eq^ 1_u);
        BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX + 1_u] ^eq^ 2_u);
        BOOST_HANA_CONSTANT_CHECK(m.rows() ^eq^ 1_u);
        BOOST_HANA_RUNTIME_CHECK (m.rows() ^eq^ 1u);
        BOOST_HANA_CONSTANT_CHECK(m.cols() ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK (m.cols() ^eq^ 2u);
        BOOST_HANA_CONSTANT_CHECK(m.size() ^eq^ 2_u);
        BOOST_HANA_RUNTIME_CHECK (m.size() ^eq^ 2u);
    }

    return 0;
}
