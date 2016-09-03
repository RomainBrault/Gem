#ifndef DIMENSIONS_HPP_INCLUDED
#define DIMENSIONS_HPP_INCLUDED

#include <boost/hana/type.hpp>
#include <boost/hana/integral_constant.hpp>

#include <gem/fwd/dimensions.hpp>
#include <gem/concept/dimensions_ring.hpp>
#include <gem/concept/dimensions_monoid.hpp>

#include <cereal/access.hpp>

namespace gem {

GemValidRuntimeDimension{T, cv, max_cv, min_cv}
class Dimension<T, cv, max_cv, min_cv>
{
public:
    using type_t = Dimension<T, cv, max_cv, min_cv>;
    using dim_t = T;
    using hana_tag = long long;

    friend class cereal::access;

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

    constexpr inline auto get_value(void) const noexcept
    {
        return _run_time;
    }

    constexpr inline auto set_value(const auto & val) const noexcept
    {
        _run_time = static_cast<T>(val);
        return *this;
    }

    static constexpr inline auto get_min(void) noexcept
    {
        return boost::hana::integral_constant<T, min_cv> {};
    }

    static constexpr inline auto get_max(void) noexcept
    {
        return boost::hana::integral_constant<T, max_cv> {};
    }

    constexpr inline operator T(void) const noexcept
    {
        // do NOT use get_value() here!
        return this->_run_time;
    }

    friend inline auto
    operator <<(std::ostream& os, const Dimension & d)
        -> std::ostream&
    {
        os << d.get_value();
        return os;
    }

private:

    template <class Archive>
    void serialize(Archive & ar)
    {
      ar(cv, max_cv, min_cv);
    }

private:
    T _run_time;

public:
    static constexpr boost::hana::type<T> type {};
};

GemValidRuntimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::type<T> Dimension<T, cv, max_cv, min_cv>::type;

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
class Dimension<T, cv, max_cv, min_cv> :
    public boost::hana::llong<max_cv>
{
public:
    using type_t = Dimension<T, cv, max_cv, min_cv>;
    using dim_t = T;
    using hana_tag = boost::hana::integral_constant_tag<long long int>;

    friend class cereal::access;

public:

    constexpr inline Dimension(void) noexcept = default;

    constexpr inline Dimension(const T & rv) noexcept
    {
        BOOST_HANA_RUNTIME_ASSERT(rv == max_cv);
    }

    constexpr inline Dimension(const Dimension & d) noexcept
    {

    }

    static constexpr inline auto get_value(void) noexcept
    {
        return boost::hana::integral_constant<T, max_cv> {};
    }

    static constexpr inline auto get_min(void) noexcept
    {
        return boost::hana::integral_constant<T, max_cv> {};
    }

    static constexpr inline auto get_max(void) noexcept
    {
        return boost::hana::integral_constant<T, max_cv> {};
    }

    friend inline auto
    operator <<(std::ostream& os, const Dimension & d)
        -> std::ostream&
    {
        os << d.get_value();
        return os;
    }

private:

    template <class Archive>
    void serialize(Archive & ar)
    {
      ar(cv, max_cv, min_cv);
    }

public:
    static constexpr boost::hana::type<T> type {};
};

GemValidCompileTimeDimension {T, cv, max_cv, min_cv}
constexpr boost::hana::type<T> Dimension<T, cv, max_cv, min_cv>::type;

/* Constraint friendly (compile time) dimension constructors.
   Takes care of cast. */
template <typename T, T cv>
constexpr inline auto
Dim(const T & value) noexcept
{
    static_assert("Incompatible type");
}

template <GemIntegral T>
constexpr inline auto
Dim(const T& value)
{
    using ust = std::make_unsigned_t<T>;
    constexpr ust max {std::numeric_limits<std::make_unsigned_t<T>>::max()};
    constexpr ust min {std::numeric_limits<std::make_unsigned_t<T>>::min()};
    return Dimension<ust, min, max, min> { static_cast<ust>(value) };
}

template <GemIntegral T, T cv_max>
constexpr inline auto
Dim(const T& value,
    const boost::hana::integral_constant<T, cv_max>& max)
{
    using ust = std::make_unsigned_t<T>;
    constexpr ust min {std::numeric_limits<std::make_unsigned_t<T>>::min()};
    return Dimension<ust, min, max, min> { static_cast<ust>(value) };
}


template <GemIntegral T, T cv_max, T cv_min>
constexpr inline auto
Dim(const T& value,
    const boost::hana::integral_constant<T, cv_max>& max,
    const boost::hana::integral_constant<T, cv_min>& min)
{
    using ust = std::make_unsigned_t<T>;
    return Dimension<ust, cv_min, cv_max, cv_min> { static_cast<ust>(value) };
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

template <GemDimension T>
struct is_arithmetic<T> : true_type { };

}

namespace cereal
{
  template <class Archive>
  struct specialize<Archive, MyDerived,
                    cereal::specialization::member_load_save> {};
  // cereal no longer has any ambiguity when serializing MyDerived
} // namespace cereal

#endif // DIMENSIONS_HPP_INCLUDED