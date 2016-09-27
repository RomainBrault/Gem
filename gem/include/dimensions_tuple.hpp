#ifndef DIMENSIONS_TUPLE_HPP_INCLUDED
#define DIMENSIONS_TUPLE_HPP_INCLUDED

#define BOOST_HANA_CONFIG_ENABLE_STRING_UDL

#include <type_traits>

#include <boost/hana/minus.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/transform.hpp>
#include <boost/hana/fold.hpp>
#include <boost/hana/string.hpp>

#include <gem/dimensions.hpp>
#include <gem/fwd/dimensions_tuple.hpp>

namespace gem {

template <bool T_flag, long long n_con, long long n_cov, GemDimension... dims>
class DimensionTuple :
    public boost::hana::tuple<dims...>
{
private:

    template <GemDimension d1, GemDimension... rd>
    struct gem_dim_common_type {
        using type =
            std::common_type_t<typename d1::dim_t,
                               typename gem_dim_common_type<rd...>::type>;
    };

    template <GemDimension d1>
    struct gem_dim_common_type<d1> {
        using type = typename d1::dim_t;
    };


public:
    using type_t = DimensionTuple<T_flag, n_con, n_cov, dims...>;
    using base_t = boost::hana::tuple<dims...>;
    using common_t = typename gem_dim_common_type<dims...>::type;

    friend class cereal::access;

public:

    static constexpr BOOST_HANA_CONSTANT_CHECK_MSG(
        (0_c < boost::hana::llong_c<sizeof...(dims)>),
        "At least one dimension must be specified.");

    using base_t::tuple;

    constexpr inline auto get_value(void) const noexcept
    {
        auto _value = [](auto && d) {
            return d.get_value();
        };
        return boost::hana::transform(*this, _value);
    }

    static constexpr inline auto get_max(void) noexcept
    {

        BOOST_HANA_CONSTEXPR_LAMBDA auto _max = [](auto && d) {
            return decltype(+d)::type::get_max();
        };
        return boost::hana::transform(boost::hana::tuple_t<dims...>, _max);
    }

    static constexpr inline auto get_min(void) noexcept
    {
        BOOST_HANA_CONSTEXPR_LAMBDA auto _min = [](auto && d) {
            return decltype(+d)::type::get_min();
        };
        return boost::hana::transform(boost::hana::tuple_t<dims...>, _min);
    }

    constexpr inline auto size(void) const noexcept {
        BOOST_HANA_CONSTEXPR_LAMBDA auto _mult = [](auto && acc,
                                                    auto && d)
        {
            return acc * d;
        };


        BOOST_HANA_CONSTEXPR_LAMBDA auto _mult_c = [](auto && acc,
                                                      auto && d)
        {
            constexpr auto max =
                boost::hana::integral_c<common_t,
                                        std::numeric_limits<common_t>::max()>;
            constexpr auto m_max =
                boost::hana::integral_c<common_t,
                                        std::numeric_limits<common_t>::max() /
                                        decltype(+d)::value>;
            constexpr auto overflow =
                boost::hana::bool_c<(acc >
                                     std::numeric_limits<common_t>::max() /
                                     decltype(+d)::value)>;
            return boost::hana::eval_if(overflow, [&] { return max; },
                                                  [&] { return acc * d; });
        };

        BOOST_HANA_CONSTEXPR_LAMBDA auto val =
            boost::hana::fold(get_value(), _mult);
        BOOST_HANA_CONSTEXPR_LAMBDA auto max =
            boost::hana::fold(get_max(), _mult_c);
        BOOST_HANA_CONSTEXPR_LAMBDA auto min =
            boost::hana::fold(get_min(), _mult);
        return Dimension<common_t,
                         (boost::hana::value(max) - boost::hana::value(min))
                         / 2 + boost::hana::value(min),
                         max, min> { val };
    }

    constexpr inline auto operator [](const auto & idx) const noexcept
        -> const std::enable_if_t<T_flag,
            decltype(base_t::operator[] (
                boost::hana::llong_c<sizeof...(dims)> -
                                     idx + GEM_START_IDX - 1_c))> &
    {
        return base_t::operator[] (
            boost::hana::llong_c<sizeof...(dims)> -
                                 idx + GEM_START_IDX - 1_c);
    }

    constexpr inline auto operator [](const auto & idx) const noexcept
        -> const std::enable_if_t<!T_flag,
            decltype(base_t::operator[] (idx - GEM_START_IDX))> &
    {
        return base_t::operator[] (idx - GEM_START_IDX);
    }

private:
    template<class Archive>
    auto save(Archive & archive) const -> void
    {
        // archive(cereal::make_size_tag(n_con));
        boost::hana::llong_c<n_con>.times.with_index(
            [this, &archive](auto index) {
                // TODO: make the string concatenation compile time.
                archive(cereal::make_nvp("contravariant",
                                         this->operator[] (GEM_START_IDX + index)));
        });
        boost::hana::llong_c<n_cov>.times.with_index(
            [this, &archive](auto index) {
                // TODO: make the string concatenation compile time.
                archive(cereal::make_nvp("covariant",
                                         this->operator[] (GEM_START_IDX + boost::hana::llong_c<n_con> + index)));
        });
    }

    template<class Archive>
    auto load(Archive & archive) -> void
    {

    }
};

} // namespage gem

#endif // DIMENSIONS_TUPLE_HPP_INCLUDED