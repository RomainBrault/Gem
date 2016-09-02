#ifndef GEM_VERSION_HPP
#define GEM_VERSION_HPP

//! @internal
//! Transforms a (version, revision, patchlevel) triple into a number of the
//! form 0xVVRRPPPP to allow comparing versions in a normalized way.
//!
//! See http://sourceforge.net/p/predef/wiki/VersionNormalization.
#define GEM_CONFIG_VERSION(version, revision, patch) \
    (((version) << 24) + ((revision) << 16) + (patch))

//! @ingroup group-config
//! Macro expanding to the major version of the library, i.e. the `x` in `x.y.z`.
#define GEM_MAJOR_VERSION 0

//! @ingroup group-config
//! Macro expanding to the minor version of the library, i.e. the `y` in `x.y.z`.
#define GEM_MINOR_VERSION 1

//! @ingroup group-config
//! Macro expanding to the patch level of the library, i.e. the `z` in `x.y.z`.
#define GEM_PATCH_VERSION 0

//! @ingroup group-config
//! Macro expanding to the full version of the library, in hexadecimal
//! representation.
//!
//! Specifically, `GEM_VERSION` expands to an hexadecimal number of the
//! form 0xVVRRPPPP, where `VV` is the major version of the library, `RR` is
//! the minor version and `PPPP` is the patch level. This allows the version
//! of the library to be compared:
//! @snippet example/version.cpp main
//!
//!
//! @note
//! The major, minor and patch versions of the library are also available
//! individually with the `GEM_{MAJOR,MINOR,PATCH}_VERSION` macros.
#define GEM_VERSION                                                         \
    GEM_CONFIG_VERSION(GEM_MAJOR_VERSION,                                   \
                       GEM_MINOR_VERSION,                                   \
                       GEM_PATCH_VERSION)                                   \
/**/

#endif // GEM_VERSION_HPP
