#ifndef TYPE_HPP_INCLUDED
#define TYPE_HPP_INCLUDED

#include <string>
#include <typeinfo>

#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#endif

namespace gem {

#ifdef __GNUG__

inline auto demangle(const char* name)
    -> std::string
{

    int status;

    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    return (status == 0) ? res.get() : name;
}

#else

// does nothing if not g++
inline auto demangle(const char* name)
    -> std::string
{
    return name;
}

#endif

template <class T>
inline auto type(const T& t)
    -> std::string
{

    return demangle(typeid(t).name());
}

} // namespace gem

#endif // TYPE_HPP_INCLUDED