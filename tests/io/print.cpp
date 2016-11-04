#include <cassert>
#include <boost/hana/assert.hpp>

#include <string>
#include <fstream>

#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>

#include <gem/gem.hpp>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    // {
    //     auto m = MatrixXd(2, 2_c);
    //     std::ofstream file {"out.bin", std::ios::binary};
    //     cereal::BinaryOutputArchive archive {file};

    //     archive(CEREAL_NVP(m));
    // }

    // {
    //     auto m = MatrixXd(2_c, 2_c);
    //     std::ofstream file {"out.xml"};
    //     cereal::XMLOutputArchive archive {file};

    //     archive(CEREAL_NVP(m.size()));
    //     // archive(CEREAL_NVP(m));
    // }

    // {
    //     auto m = MatrixXd(2_c, 2_c);
    //     std::ofstream file {"out.json"};
    //     cereal::JSONOutputArchive archive {file};

    //     archive(CEREAL_NVP(m.size()));
    //     // archive(CEREAL_NVP(m));
    // }

    // {
    //     auto m = MatrixXd(2, 2);
    //     std::string s << m;
    // }

    // {
    //     auto m = MatrixXd(2, 2_c);
    //     std::string s << m;
    // }

    // {
    //     auto m = MatrixXd(2_c, 2);
    //     std::string s << m;
    // }

}