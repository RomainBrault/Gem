#ifndef TENSOR_HPP_INCLUDED
#define TENSOR_HPP_INCLUDED

#include <gem/tensor_base.hpp>

namespace gem {

template <typename dtype, long long n_con, long long n_cov, class... dims>
class Tensor :
    public TensorBase<dtype, n_con, n_cov, dims...>
{

public:
    using base_t = TensorBase<dtype, n_con, n_cov, dims...>;

public:

    constexpr inline Tensor(const dims&... d) noexcept :
        base_t(d...), _memory(nullptr)
    {

    }

private:
    dtype* _memory;
};


template <typename R, typename C>
constexpr inline auto MatrixXd(const R & rows = 1_u, const C & cols = 1_u)
{
    auto dim1 = Dim(rows);
    auto dim2 = Dim(cols);
    return TensorBase<double, 1, 1, decltype(dim1), decltype(dim2)>(dim1, dim2);
}

} // namespace gem

#endif // TENSOR_HPP_INCLUDED