#ifndef TENSOR_HPP_INCLUDED
#define TENSOR_HPP_INCLUDED

#include <gem/tensor_base.hpp>

namespace gem {

template <typename dtype, class... dims>
class Tensor :
    public TensorBase<dtype, dims...>
{

public:
    using base_t = TensorBase<dtype, dims...>;

public:

    constexpr inline Tensor(const dims&... d) noexcept :
        base_t(d...), _memory(nullptr)
    {

    }

private:
    dtype* _memory;
};


template <typename R, typename C>
constexpr inline auto MatrixXd(const R & rows = 0, const C & cols = 0)
{
    auto dim1 = Dim(rows);
    auto dim2 = Dim(cols);
    return TensorBase<double, decltype(dim1), decltype(dim2)>(dim1, dim2);
}

} // namespace gem

#endif // TENSOR_HPP_INCLUDED