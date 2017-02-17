/*!
@file
Defines forward `gem::dimension`.

@copyright Romain Brault 2013-2016
(See accompanying file LICENSE)
 */

#ifndef FWD_DIMENSIONS_HPP_INCLUDED
#define FWD_DIMENSIONS_HPP_INCLUDED

#include <boost/hana/core/tag_of.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/type.hpp>

#include <gem/concept/dimensions.hpp>

//////////////////////////////////////////////////////////////////////////
// Dimension forward declarations
//////////////////////////////////////////////////////////////////////////

namespace gem {

concepts::detail::UnsignedIntegral {T}
class DimensionTag;

concepts::detail::UnsignedIntegral {T}
class RuntimeDimensionTag;

concepts::detail::UnsignedIntegral {T}
class CompileTimeDimensionTag;

template <typename T, T cv, T max, T min>
class Dimension;

}  // namespace gem

//////////////////////////////////////////////////////////////////////////
// Dimension traits
//////////////////////////////////////////////////////////////////////////

namespace gem::detail {

template <typename>
struct is_dimension_impl;

template <typename T>
using is_dimension = is_dimension_impl<std::decay_t<T>>;

template <typename T>
using is_dimension_t = typename is_dimension<T>::type;

template <typename T>
constexpr auto is_dimension_v = is_dimension<T>::value;

}  // namespace gem::detail

//////////////////////////////////////////////////////////////////////////
// Dimension template deduction guide
//////////////////////////////////////////////////////////////////////////

namespace gem::hack {
    /* FIXME: concept simulation hack to avoid compile time error when calling
     * make_unsigned on integral_constant.
     *
     * Note that it cannot be done at concept level since gcc still try to
     * instanciate all template deduction guides to choose the most suitable.
     */

    gem::concepts::detail::Integral {T}
    struct safe_make_unsigned
    {
        static_assert(!std::is_same_v<boost::hana::tag_of_t<T>,
                      boost::hana::integral_constant_tag<T>>);
        using type = std::make_unsigned_t<T>;
    };

    /* Shortcuts */
    gem::concepts::detail::Integral {T}
    using safe_make_unsigned_t =
        typename safe_make_unsigned<T>::type;

    gem::concepts::detail::Integral {T}
    constexpr auto safe_make_unsigned_max =
        std::numeric_limits<safe_make_unsigned_t<T>>::max();

}  // namespace gem::hack

namespace gem {

gem::concepts::detail::IntegralConstant {T, cv}
Dimension(const boost::hana::integral_constant<T, cv> &)
    -> Dimension<hack::safe_make_unsigned_t<T>, cv, cv, cv>;

gem::concepts::detail::Integral {T}
Dimension(const T & rv)
    -> Dimension<hack::safe_make_unsigned_t<T>,
                 (hack::safe_make_unsigned_max<T> - 1) / 2 + 1,
                 hack::safe_make_unsigned_max<T>, 1>;

template <gem::concepts::detail::Integral T, T max>
Dimension(const T& value,
          const boost::hana::integral_constant<T, max>&)
    -> Dimension<hack::safe_make_unsigned_t<T>,
                 (max - 1) / 2 + 1, max, 1>;

template <gem::concepts::detail::Integral T, T max, T min>
Dimension(const T& value,
          const boost::hana::integral_constant<T, max>&,
          const boost::hana::integral_constant<T, min>&)
    -> Dimension<hack::safe_make_unsigned_t<T>,
                 (max - min) / 2 + min, max, min>;

}  // namespace gem

//////////////////////////////////////////////////////////////////////////
// Dimension concepts
//////////////////////////////////////////////////////////////////////////

namespace gem::concepts {

template <class D>
concept bool Dimension =
    boost::hana::value(gem::detail::is_dimension_impl<D> {});

Dimension {D}
concept bool CompileTimeDimension =
    boost::hana::value(D::min == D::max);

Dimension {D}
concept bool RuntimeDimension =
    !CompileTimeDimension<D>;

}  // namespace gem::concepts

#endif  // !FWD_DIMENSIONS_HPP_INCLUDED
