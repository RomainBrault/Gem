#ifndef GEM_LITTERALS_HPP_INCLUDED
#define GEM_LITTERALS_HPP_INCLUDED

#include <boost/hana/integral_constant.hpp>

#include <gem/concept/dimensions.hpp>

namespace gem::literals {

template <char ...c>
constexpr inline auto
operator"" _u(void) {
    return boost::hana::GEM_DEFAULT_DIM_T<
        boost::hana::ic_detail::parse<sizeof...(c)>({c...})>{};
}

}  // namespage gem::litterals

#if GEM_USE_LITTERALS == true
using namespace boost::hana::literals;
using namespace gem::literals;
#endif  // !USE_GEM_LITTERALS

#endif  // !GEM_LITTERALS_HPP_INCLUDED
