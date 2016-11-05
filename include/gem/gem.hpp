/*!
@file
Includes all the library components except the adapters for external
libraries.

@copyright Romain Brault 2013-2016
(See accompanying file LICENSE)
 */

#ifndef GEM_HPP_INCLUDED
#define GEM_HPP_INCLUDED

//! @defgroup group-concepts Concepts
//! Concepts provided by the library.

#ifdef GEM_DOXYGEN_INVOKED
//! Namespace containing everything in the library.
namespace gem {
    //! Namespace containing C++14 user-defined literals provided by Gem.
    namespace literals {}
}
#endif

#include <gem/version.hpp>
#include <gem/litterals.hpp>
#include <gem/tensor.hpp>

#endif // GEM_HPP_INCLUDED