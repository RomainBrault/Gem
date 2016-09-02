#include <cassert>
#include <boost/hana/assert.hpp>

#include <gem/gem.hpp>

#include <iostream>

using namespace gem;
using namespace boost::hana;

auto main(void) -> int
{

    {
        auto m = MatrixXd(0_c, 0_c);
        BOOST_HANA_CONSTANT_CHECK(m.n_dims == 2_c);
    }

    {
        auto m = MatrixXd(1, 2);
        BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX      ] == 1);
        BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX + 1_c] == 2);
        BOOST_HANA_RUNTIME_CHECK (m.rows() == 1);
        BOOST_HANA_RUNTIME_CHECK (m.cols() == 2);
    }

    {
        auto m = MatrixXd(1_c, 2);
        BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX      ] == 1);
        BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX + 1_c] == 2);
        BOOST_HANA_CONSTANT_CHECK(m.rows() == 1_c);
        BOOST_HANA_RUNTIME_CHECK (m.cols() == 2  );
    }

    {
        auto m = MatrixXd(1, 2_c);
        BOOST_HANA_RUNTIME_CHECK (m.dim[GEM_START_IDX      ] == 1  );
        BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX + 1_c] == 2_c);
        BOOST_HANA_RUNTIME_CHECK (m.rows() == 1  );
        BOOST_HANA_CONSTANT_CHECK(m.cols() == 2_c);
    }

    {
        auto m = MatrixXd(1_c, 2_c);
        BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX      ] == 1_c);
        BOOST_HANA_CONSTANT_CHECK(m.dim[GEM_START_IDX + 1_c] == 2_c);
        BOOST_HANA_CONSTANT_CHECK(m.rows() == 1_c);
        BOOST_HANA_CONSTANT_CHECK(m.cols() == 2_c);
    }

    {
        auto m = MatrixXd(2_c, 2_c);
        BOOST_HANA_CONSTANT_CHECK(m.size() == Dim(4_c));
        BOOST_HANA_CONSTANT_CHECK(m.size() == 4_c);
    }

    {
        auto m = MatrixXd(2, 2);
        BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4));
        BOOST_HANA_RUNTIME_CHECK(m.size() == 4);
    }

    // {

    // {
    //     BOOST_HANA_CONSTANT_CHECK(int_c<6> / int_c<3> == boost::hana::int_c<2>);
    // }

        // auto m = MatrixXd(2, 2_c);
        // BOOST_HANA_RUNTIME_CHECK(mult_impl<decltype(m.dim[1_c]), decltype(m.dim[2_c])>::apply(m.dim[1_c], m.dim[2_c]) == 4);
        // BOOST_HANA_RUNTIME_CHECK(mult(m.dim[1_c], m.dim[2_c]) == 4);
        // auto t = mult(m.dim[1_c], m.dim[2_c]);
        // std::cout << print(type_c<decltype(m.dim[1_c])>) << std::endl;
        // std::cout << print(type_c<decltype(m.dim[2_c])>) << std::endl;
        // std::cout << print(type_c<common<decltype(m.dim[1_c]), decltype(m.dim[2_c])>::type>) << std::endl;

        // using ct = common<decltype(m.dim[1_c]), decltype(m.dim[2_c])>::type;

        // auto t1 = to<ct>(m.dim[1_c]);
        // auto t2 = to<ct>(m.dim[2_c]);

        // std::cout << print(type_c<decltype(t1)>) << std::endl;
        // std::cout << print(type_c<decltype(t2)>) << std::endl;
        // std::cout << t1 << ' ' << t2 << std::endl;

        // auto t = true ? std::declval<decltype(m.dim[1_c])>() : std::declval<decltype(m.dim[2_c])>();
        // std::cout << print(type_c<decltype(t)>) << std::endl;
        // BOOST_HANA_RUNTIME_CHECK(false);
        // BOOST_HANA_RUNTIME_CHECK(m.size() == Dim(4));
        // BOOST_HANA_RUNTIME_CHECK(m.size() == 4);

        // BOOST_HANA_RUNTIME_CHECK(boost::hana::detail::has_nontrivial_common_embedding<Ring, decltype(m.dim[1_c]), decltype(m.dim[2_c])>::value);

        // mult(m.dim[1_c], m.dim[2_c]);
        // std::cout << static_cast<Dimension<unsigned, 0, 2, 2>>(2) << std::endl;
        // std::cout << one<Dimension<unsigned, 0, 2, 2>>() << std::endl;

        // static constexpr bool value = !is_default<one_impl<Tag>>::value &&
        //                               !is_default<mult_impl<Tag, Tag>>::value;
        // std::cout << m.dim[1_c] << std::endl;
        // BOOST_HANA_RUNTIME_CHECK(false);

        // BOOST_HANA_RUNTIME_CHECK(!is_default<mult_impl<decltype(m.dim[1_c]),
        //                                                decltype(m.dim[2_c])>>::value);

        // auto t = static_cast<Dimension<unsigned, 0, 2, 2>>(1);
        // std::cout << one<integral_constant<long, 1>>() << std::endl;
        // BOOST_HANA_RUNTIME_CHECK(static_cast<Dimension<unsigned, 2, 2, 2>>(1) == 1);
    // }
    // }

    // {
    //     auto m = MatrixXd(2_c, 2);
    //     BOOST_HANA_RUNTIME_CHECK(m.size() == 4);
    // }

    // {
    //     auto m = MatrixXd(2, 2_c);
    //     BOOST_HANA_RUNTIME_CHECK(m.size() == 4);
    // }

    {
        // auto m = MatrixXd(2_c, 2_c);
        // auto d = Dimension<unsigned, 2, 2, 2> {};
        // // std::cout << d << std::endl;
        // auto d = boost::hana::to<Dimension<unsigned, 0, 2, 0>>(Dimension<unsigned, 2, 2, 2> {});
        // std::cout << d << std::endl;
        // BOOST_HANA_RUNTIME_CHECK(m.size() == 4);
    }

    return 0;
}
