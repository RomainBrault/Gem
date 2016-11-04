#ifndef DIMENSIONS_HPP_INCLUDED
#define DIMENSIONS_HPP_INCLUDED

#include <boost/hana/type.hpp>
#include <boost/hana/integral_constant.hpp>

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

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
void save(auto & archive,
          const gem::Dimension<T, cv, max_cv, min_cv> & m)
{
    archive(cereal::make_nvp("dimension_type",
                             cereal::util::demangle(typeid(unsigned long long).name())),
            cereal::make_nvp("hint", 2),
            cereal::make_nvp("max", 2),
            cereal::make_nvp("min", 2),
            cereal::make_nvp("real", 2));
}

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
void load(auto & archive,
          gem::Dimension<T, cv, max_cv, min_cv> & m,
          std::uint32_t version)
{

}

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
void save(auto & archive,
          const gem::Dimension<T, cv, max_cv, min_cv> & m,
          std::uint32_t version)
{
    archive(cereal::make_nvp("dimension_type",
                             gem::demangle(typeid(T).name())),
            cereal::make_nvp("hint", cv),
            cereal::make_nvp("max", max_cv),
            cereal::make_nvp("min", min_cv),
            cereal::make_nvp("real", m.value()));
}

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
void load(auto & archive,
          gem::Dimension<T, cv, max_cv, min_cv> & m,
          std::uint32_t const version)
{

}

} // namespace gem

namespace cereal {
// template<class Archive, typename T, T cv, T max_cv, T min_cv>
// struct specialize<Archive, gem::Dimension<T, cv, max_cv, min_cv>,
//                   cereal::specialization::member_load_save> {};
// cereal no longer has any ambiguity when serializing Dimension

template<class Archive, typename T, T cv, T max_cv, T min_cv>
struct specialize<Archive, gem::Dimension<T, cv, max_cv, min_cv>,
                  specialization::non_member_load_save> {};

namespace detail {

GemValidDimension {T, cv, max_cv, min_cv}
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
}; /* end Version */

GemValidDimension {T, cv, max_cv, min_cv}
const std::uint32_t Version<gem::Dimension<T, cv, max_cv, min_cv>>::version =
    Version<gem::Dimension<T, cv, max_cv, min_cv>>::registerVersion();

} // namespace detail

} // namespace cereal





namespace gem {

GemValidRuntimeDimension{T, cv, max_cv, min_cv}
class Dimension<T, cv, max_cv, min_cv>
{
public:
    using type_t = Dimension<T, cv, max_cv, min_cv>;
    using dim_t = T;

    static constexpr boost::hana::type<dim_t> type {};
    static constexpr boost::hana::integral_constant<dim_t, cv> hint {};
    static constexpr boost::hana::integral_constant<dim_t, max_cv> max {};
    static constexpr boost::hana::integral_constant<dim_t, min_cv> min {};

public:
    constexpr inline Dimension(void) = delete;

    constexpr inline Dimension(const T & rv) noexcept :
        _run_time {rv}
    {
        BOOST_HANA_RUNTIME_CHECK(max_cv >= rv);
        BOOST_HANA_RUNTIME_CHECK(rv >= min_cv);
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

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::type<T>
    Dimension<T, cv, max_cv, min_cv>::type;

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::integral_constant<T, cv>
    Dimension<T, cv, max_cv, min_cv>::hint;

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::integral_constant<T, max_cv>
    Dimension<T, cv, max_cv, min_cv>::max;

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::integral_constant<T, min_cv>
    Dimension<T, cv, max_cv, min_cv>::min;





GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
class Dimension<T, cv, max_cv, min_cv>
{
public:
    using type_t = Dimension<T, cv, max_cv, min_cv>;
    using dim_t = T;

    static constexpr boost::hana::type<dim_t> type {};
    static constexpr boost::hana::integral_constant<dim_t, cv> hint {};
    static constexpr boost::hana::integral_constant<dim_t, max_cv> max {};
    static constexpr boost::hana::integral_constant<dim_t, min_cv> min {};

public:

    constexpr inline Dimension(void) noexcept = default;

    constexpr inline Dimension(const T &) noexcept = delete;

    constexpr inline Dimension(const Dimension & d) noexcept
    {

    }

    static constexpr inline auto value(void) noexcept
    {
        return hint;
    }

    constexpr inline auto value(const auto & val) const = delete;

    friend inline auto
    operator <<(std::ostream& os, const Dimension & d)
        -> std::ostream&
    {
        os << d.value();
        return os;
    }
};

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::type<T>
    Dimension<T, cv, max_cv, min_cv>::type;

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::integral_constant<T, cv>
    Dimension<T, cv, max_cv, min_cv>::hint;

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::integral_constant<T, max_cv>
    Dimension<T, cv, max_cv, min_cv>::max;

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::integral_constant<T, min_cv>
    Dimension<T, cv, max_cv, min_cv>::min;

/* Constraint friendly (compile time) dimension constructors.
   Takes care of cast. */
template <typename T, T cv>
constexpr inline auto
Dim(const T & value) noexcept
{
    BOOST_HANA_CONSTANT_CHECK_MSG(boost::hana::false_c, "Incompatible type");
}

template <GemIntegral T>
constexpr inline auto
Dim(const T& value)
{
    using ust = std::make_unsigned_t<T>;
    constexpr ust max {std::numeric_limits<std::make_unsigned_t<T>>::max()};
    return Dimension<ust, (max - 1) / 2 + 1, max, 1> {
        static_cast<ust>(value)
    };
}

template <GemIntegral T, T cv_max>
constexpr inline auto
Dim(const T& value,
    const boost::hana::integral_constant<T, cv_max>& max)
{
    using ust = std::make_unsigned_t<T>;
    return Dimension<ust, (cv_max - 1) / 2 + 1, cv_max, 1> {
        static_cast<ust>(value)
    };
}


template <GemIntegral T, T cv_max, T cv_min>
constexpr inline auto
Dim(const T& value,
    const boost::hana::integral_constant<T, cv_max>& max,
    const boost::hana::integral_constant<T, cv_min>& min)
{
    using ust = std::make_unsigned_t<T>;
    return Dimension<ust, (cv_max - cv_min) / 2 + cv_min, cv_max, cv_min> {
        static_cast<ust>(value)
    };
}

template <GemIntegral T, T cv>
constexpr inline auto
Dim(const boost::hana::integral_constant<T, cv> & value) noexcept
{
    return Dimension<typename std::make_unsigned_t<T>, cv, cv, cv> {};
}

namespace detail {

template <typename>
struct is_gem_dimension_impl :
    boost::hana::false_
{

};

GemValidDimension {T, cv, max_cv, min_cv}
struct is_gem_dimension_impl<gem::Dimension<T, cv, max_cv, min_cv>> :
    boost::hana::true_
{

};

template <typename>
struct is_gem_runtime_dimension_impl :
    boost::hana::false_
{

};

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
struct is_gem_runtime_dimension_impl<gem::Dimension<T, cv, max_cv, min_cv>> :
    boost::hana::true_
{

};

template <typename>
struct is_gem_compile_time_dimension_impl :
    boost::hana::false_
{

};

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
struct is_gem_compile_time_dimension_impl<gem::Dimension<T, cv,
                                                         max_cv, min_cv>> :
    boost::hana::true_
{

};

} // namespace detail

} // namespace gem

namespace std {

template<GemDimension T>
struct is_arithmetic<T> : true_type { };

} // namespace std

#endif // DIMENSIONS_HPP_INCLUDED