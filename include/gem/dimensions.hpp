/*!
@file
Defines `gem::dimension`.

@copyright Romain Brault 2013-2016
(See accompanying file LICENSE)
 */

#ifndef GEM_DIMENSIONS_HPP_INCLUDED
#define GEM_DIMENSIONS_HPP_INCLUDED

#include <boost/hana/type.hpp>
#include <boost/hana/bool.hpp>

#include <cereal/cereal.hpp>
#include <cereal/details/util.hpp>

#include <gem/version.hpp>
#include <gem/fwd/dimensions.hpp>
#include <gem/concept/dimensions_to.hpp>
#include <gem/concept/dimensions_common.hpp>
#include <gem/concept/dimensions_comparable.hpp>
#include <gem/concept/dimensions_orderable.hpp>
#include <gem/concept/dimensions_monoid.hpp>
#include <gem/concept/dimensions_group.hpp>
#include <gem/concept/dimensions_ring.hpp>

namespace gem {

gem::concepts::detail::CompileTimeDimension {T, cv, max_cv, min_cv}
void save(auto & archive,
          const gem::Dimension<T, cv, max_cv, min_cv> & m)
{
    archive(cereal::make_nvp("hint", 2),
            cereal::make_nvp("max", 2),
            cereal::make_nvp("min", 2),
            cereal::make_nvp("real", 2));
}

gem::concepts::detail::CompileTimeDimension {T, cv, max_cv, min_cv}
void load(auto & archive,
          gem::Dimension<T, cv, max_cv, min_cv> & m,
          std::uint32_t version)
{

}

gem::concepts::detail::RuntimeDimension {T, cv, max_cv, min_cv}
void save(auto & archive,
          const gem::Dimension<T, cv, max_cv, min_cv> & m,
          std::uint32_t version)
{
    archive(cereal::make_nvp("hint", cv),
            cereal::make_nvp("max", max_cv),
            cereal::make_nvp("min", min_cv),
            cereal::make_nvp("real", m.value()));
}

gem::concepts::detail::RuntimeDimension {T, cv, max_cv, min_cv}
void load(auto & archive,
          gem::Dimension<T, cv, max_cv, min_cv> & m,
          std::uint32_t const version)
{

}

} // namespace gem

namespace cereal {

template<class Archive, typename T, T cv, T max_cv, T min_cv>
struct specialize<Archive, gem::Dimension<T, cv, max_cv, min_cv>,
                  specialization::non_member_load_save> {};

namespace detail {

gem::concepts::detail::Dimension {T, cv, max_cv, min_cv}
struct Version<gem::Dimension<T, cv, max_cv, min_cv>>
{
    static const std::uint32_t version;

    static std::uint32_t registerVersion(void) {
        ::cereal::detail::StaticObject<Versions>::getInstance().mapping.emplace(
            std::type_index(
                typeid(gem::Dimension<T, cv, max_cv, min_cv>)).hash_code(),
                GEM_VERSION);
        return GEM_VERSION;
    }
    static void unused() { (void)version; }
};

gem::concepts::detail::Dimension {T, cv, max_cv, min_cv}
const std::uint32_t Version<gem::Dimension<T, cv, max_cv, min_cv>>::version =
    Version<gem::Dimension<T, cv, max_cv, min_cv>>::registerVersion();

} // namespace detail

} // namespace cereal

//////////////////////////////////////////////////////////////////////////
// DimensionTag implementation
//////////////////////////////////////////////////////////////////////////

namespace gem {

concepts::detail::UnsignedIntegral {T}
struct DimensionTag
{
    using value_type = T;
};

concepts::detail::UnsignedIntegral {T}
struct RuntimeDimensionTag :
    DimensionTag<T>
{

};

concepts::detail::UnsignedIntegral {T}
struct CompileTimeDimensionTag :
    DimensionTag<T>
{

};

}  // namespace gem

//////////////////////////////////////////////////////////////////////////
// Runtime dimension implementation
//////////////////////////////////////////////////////////////////////////
namespace gem {

concepts::detail::RuntimeDimension{T, cv, max_cv, min_cv}
class Dimension<T, cv, max_cv, min_cv>
{
public:
    using type_t = Dimension<T, cv, max_cv, min_cv>;
    using dim_t = T;
    using hana_tag = RuntimeDimensionTag<T>;

    static inline constexpr auto type {boost::hana::type_c<dim_t>};
    static inline constexpr auto hint {boost::hana::integral_c<dim_t, cv>};
    static inline constexpr auto max  {boost::hana::integral_c<dim_t, max_cv>};
    static inline constexpr auto min  {boost::hana::integral_c<dim_t, min_cv>};

public:
    constexpr inline Dimension(void) = delete;

    constexpr inline Dimension(const T & rv) noexcept :
        _run_time {rv}
    {
        BOOST_HANA_RUNTIME_CHECK(max_cv    >= _run_time);
        BOOST_HANA_RUNTIME_CHECK(_run_time >= min_cv);
    }

    constexpr inline Dimension(const Dimension & d) noexcept :
        _run_time {d._run_time}
    {

    }

    template<T ncv>
    constexpr inline
    Dimension(const Dimension<T, ncv, max_cv, min_cv> & d) noexcept :
        _run_time {ncv}
    {

    }

    constexpr inline auto value(void) const noexcept
    {
        return _run_time;
    }

    constexpr inline auto value(const auto & val) noexcept
    {
        _run_time = static_cast<T>(val);
        return *this;
    }

    friend inline auto
    operator <<(std::ostream& os, const Dimension & d)
        -> std::ostream&
    {
        os << d.value();
        return os;
    }

private:
    T _run_time;
};

}  // namespace gem

//////////////////////////////////////////////////////////////////////////
// Compile time dimension implementation
//////////////////////////////////////////////////////////////////////////
namespace gem {

gem::concepts::detail::CompileTimeDimension {T, cv, max_cv, min_cv}
class Dimension<T, cv, max_cv, min_cv>
{
public:
    using type_t = Dimension<T, cv, max_cv, min_cv>;
    using dim_t = T;
    using hana_tag = CompileTimeDimensionTag<T>;

    static inline constexpr auto type {boost::hana::type_c<dim_t>};
    static inline constexpr auto hint {boost::hana::integral_c<dim_t, cv>};
    static inline constexpr auto max  {boost::hana::integral_c<dim_t, max_cv>};
    static inline constexpr auto min  {boost::hana::integral_c<dim_t, min_cv>};

public:
    constexpr inline Dimension(void) noexcept = default;

    constexpr inline Dimension(const T &) noexcept = delete;

    template <typename T2>
    constexpr inline
    Dimension(const boost::hana::integral_constant<T2, cv> &) noexcept
    {

    }

    constexpr inline Dimension(const Dimension &) noexcept
    {

    }

    static constexpr inline auto value(void) noexcept
    {
        return hint;
    }

    constexpr inline auto value(const auto & val) const = delete;

    // friend inline auto
    // operator <<(std::ostream& os, const Dimension & d)
    //     -> std::ostream&
    // {
    //     os << d.value();
    //     return os;
    // }
};

}  // namespace gem

//////////////////////////////////////////////////////////////////////////
// Dimensions traits implementation
//////////////////////////////////////////////////////////////////////////
namespace gem::detail {

template <typename>
struct is_dimension_impl :
    boost::hana::false_
{

};

gem::concepts::detail::Dimension {T, cv, max, min}
struct is_dimension_impl<gem::Dimension<T, cv, max, min>> :
    boost::hana::true_
{

};

}  // namespace gem::detail

#endif  // !GEM_DIMENSIONS_HPP_INCLUDED
