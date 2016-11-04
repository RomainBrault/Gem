// #include <iostream>
#include <typeinfo>
#include <boost/hana/experimental/printable.hpp>

// #define USE_
#include <gem/tensor.hpp>

using namespace gem;
using namespace boost::hana;
// using namespace boost::hana::experimental;

// template <typename T>
// inline auto operator<<(std::ostream& os, const boost::hana::type<T>& type)
//     -> std::ostream&
// {
//     os << boost::hana::experimental::print(type);
//     return os;
// }

int main(void) {

    // auto dim1 = Dim<0> {2};
    // auto dim2 = Dim<2> {};

    // // dim1 = dim1 * 2;
    // constexpr size_t v = dim2;

    // std::cout << (dim1 == 0) << std::endl;
    // std::cout << dim2 << std::endl;
    // std::cout << dim1 + dim2 << std::endl;
    // // std::cout << typeid(dim1 + dim2).name() << std::endl;
    // std::cout << sizeof(dim1) << std::endl;
    // std::cout << sizeof(dim2) << std::endl;

    auto m = MatrixXd(10_c, 20_c);
    // auto m2 = MatrixXd(20, 10);

    // for (long long i = 0; i < 15000000000; ++i) {
    // 	m = m.transpose();
    //     m = m.transpose();
    // }
    // (100000_c).times(m.transpose());
    // std::cout << m.dim[1_u] << std::endl;
    // std::cout << m.dim[2_u] << std::endl;
    // std::cout << print(m.transpose()) << std::endl;

    // m2 = std::move(m);
    // std::cout << m.transpose() << std::endl;
    // std::cout << typeid(m.size()).name() << std::endl;
    std::cout << m.size() << std::endl;
    // std::cout << print(m.size().type) << std::endl;
 //    std::cout << m << std::endl;
 //    std::cout << m2<< std::endl;
    // constexpr auto m2(m);

 //    // std::cout << sizeof(m.dim[0_c].type) << std::endl;
 //    std::cout << sizeof(m2) << std::endl;
 //    // std::cout << sizeof(m.dim) << std::endl;
 //    // std::cout << m.dim[0_c].type << std::endl;
 //    // std::cout << m2.dim[0_c] << std::endl;
 //    // std::cout << m2.dim[1_c] << std::endl;
 //    // std::cout << m2.dim[2_c] << std::endl;
 //    // m.dim[0_c] = 1;
	// std::cout << m.n_dims << std::endl;

	// std::cout << m2.rows() << std::endl;
	// std::cout << m2.cols() << std::endl;
	// std::cout << m2.size() << std::endl;

    // for (int i = 0; i < m.dim(1_c); ++i) {
    // 	std::cout << i << std::endl;
    // }

	// std::cout << Dim<size_t>(10ul, 2_c, 0_c) << std::endl;
    // m "1:2, 3:4"

    // auto dim1 = Dim<unsigned long>(10);
    // auto dim2 = Dim<unsigned long>(10_c);
    // auto dim3 = Dim<unsigned long>(10_c);

    // std::cout << typeid(dim2 * dim2).name() << std::endl;
    // std::cout << dim2 * dim3 << std::endl;
    // std::cout << (mult(dim1, mult(dim2, dim3)) == mult(mult(dim1, dim2), dim3)) << std::endl;
    // std::cout << plus(dim1, dim2) << std::endl;
    // std::cout << (mult(dim1, one<decltype>()) == dim1 << std::endl;
    // boost::hana::mult_impl<decltype(dim2), decltype(dim3)>::apply(dim2, dim3);
    // std::cout << dim2 << std::endl;
    // std::cout << mult(dim2, dim3) << std::endl;
    // mult(dim1, mult(dim2, dim3));
    // std::cout << dim2 * dim3 << std::endl;

    return 0;
}