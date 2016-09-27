#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

//     /* CHECK DIMENSION */
//     {
//         auto m = MatrixXd(1_c, 1_c);
//         BOOST_HANA_CONSTANT_CHECK(m.order == 2_c);
//     }

//     {
//         auto m = MatrixXd(1, 2);
//         BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX      ] == 1);
//         BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX + 1_c] == 2);
//         BOOST_HANA_RUNTIME_CHECK (m.rows() == 1_c);
//         BOOST_HANA_RUNTIME_CHECK (m.cols() == 2_c);
//         BOOST_HANA_RUNTIME_CHECK (m.rows() == 1);
//         BOOST_HANA_RUNTIME_CHECK (m.cols() == 2);
//     }

//     {
//         auto m = MatrixXd(1_c, 2);
//         BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX      ] == 1);
//         BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX + 1_c] == 2);
//         BOOST_HANA_CONSTANT_CHECK(m.rows() == 1_c);
//         BOOST_HANA_RUNTIME_CHECK (m.cols() == 2_c);
//         BOOST_HANA_RUNTIME_CHECK (m.rows() == 1);
//         BOOST_HANA_RUNTIME_CHECK (m.cols() == 2);
//     }

//     {
//         auto m = MatrixXd(1, 2_c);
//         BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX      ] == 1  );
//         BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX + 1_c] == 2_c);
//         BOOST_HANA_RUNTIME_CHECK (m.rows() == 1_c);
//         BOOST_HANA_CONSTANT_CHECK(m.cols() == 2_c);
//         BOOST_HANA_RUNTIME_CHECK (m.rows() == 1);
//         BOOST_HANA_RUNTIME_CHECK (m.cols() == 2);
//     }

//     {
//         auto m = MatrixXd(1_c, 2_c);
//         BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX      ] == 1_c);
//         BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX + 1_c] == 2_c);
//         BOOST_HANA_CONSTANT_CHECK(m.rows() == 1_c);
//         BOOST_HANA_CONSTANT_CHECK(m.cols() == 2_c);
//         BOOST_HANA_RUNTIME_CHECK (m.rows() == 1);
//         BOOST_HANA_RUNTIME_CHECK (m.cols() == 2);
//     }

//     /* CHECK SIZE */
//     {
//         auto m = MatrixXd(2_c, 2_c);
//         BOOST_HANA_CONSTANT_CHECK(m.size() == Dim(4_c));
//         BOOST_HANA_RUNTIME_CHECK (m.size() == Dim(4));
//         BOOST_HANA_CONSTANT_CHECK(m.size() == 4_c);
//         BOOST_HANA_RUNTIME_CHECK (m.size() == 4);
//     }

//     {
//         auto m = MatrixXd(2, 2);
//         BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4_c));
//         BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4));
//         BOOST_HANA_RUNTIME_CHECK(m.size() == 4_c);
//         BOOST_HANA_RUNTIME_CHECK(m.size() == 4);
//     }

//     {
//         auto m = MatrixXd(2, 2_c);
//         BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4_c));
//         BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4));
//         BOOST_HANA_RUNTIME_CHECK(m.size() == 4_c);
//         BOOST_HANA_RUNTIME_CHECK(m.size() == 4);
//     }

//     {
//         auto m = MatrixXd(2_c, 2);
//         BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4_c));
//         BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4));
//         BOOST_HANA_RUNTIME_CHECK(m.size() == 4_c);
//         BOOST_HANA_RUNTIME_CHECK(m.size() == 4);
//     }

    return 0;
}
