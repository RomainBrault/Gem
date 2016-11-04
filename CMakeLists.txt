cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

##############################################################################
# Setup project
#
# We parse the canonical version number located in <gem/version.hpp>.
# This is done to allow the library to be used without requiring a proper
# installation during which the version would be written to this header.
##############################################################################
foreach(level MAJOR MINOR PATCH)
    file(STRINGS include/gem/version.hpp
                 _define_${level}
                 REGEX "#define GEM_${level}_VERSION")
    string(REGEX MATCH "([0-9]+)" _version_${level} "${_define_${level}}")
endforeach()

set(gem_VERSION_STRING "${_version_MAJOR}.${_version_MINOR}.${_version_PATCH}")
project(gem VERSION ${Gem_VERSION_STRING} LANGUAGES CXX)

# Perform checks to make sure we support the current compiler
include(CheckCxxCompilerSupport)

##############################################################################
# Setup CMake options
##############################################################################
option(gem_ENABLE_WERROR
       "Fail and stop if a warning is triggered." ON)
option(gem_ENABLE_MEMCHECK
       "Run the unit tests and examples under Valgrind if it is found." OFF)

##############################################################################
# Setup compiler flags
# (more can be set on a per-target basis or in subdirectories)
##############################################################################
include(CheckCXXCompilerFlag)
macro(gem_append_flag testname flag)
    check_cxx_compiler_flag(${flag} ${testname})
    if (${testname})
        add_compile_options(${flag})
    endif()
endmacro()

# Compiler flags controlled by CMake options above
if (gem_ENABLE_WERROR)
    gem_append_flag(gem_HAS_WERROR -Werror)
    gem_append_flag(gem_HAS_WX -WX)
endif()

# Other compiler flags
gem_append_flag(gem_HAS_FDIAGNOSTICS_COLOR         -fdiagnostics-color)
gem_append_flag(gem_HAS_FTEMPLATE_BACKTRACE_LIMIT  -ftemplate-backtrace-limit=0)
gem_append_flag(gem_HAS_PEDANTIC                   -pedantic)
gem_append_flag(gem_HAS_STDCXX17                   -std=c++1z)
gem_append_flag(gem_HAS_QUNUSED_ARGUMENTS          -Qunused-arguments)
gem_append_flag(gem_HAS_W                          -W)
gem_append_flag(gem_HAS_WALL                       -Wall)
gem_append_flag(gem_HAS_WEXTRA                     -Wextra)
gem_append_flag(gem_HAS_WNO_UNUSED_LOCAL_TYPEDEFS  -Wno-unused-local-typedefs)
gem_append_flag(gem_HAS_WWRITE_STRINGS             -Wwrite-strings)
gem_append_flag(gem_HAS_CONCEPTS                   -fconcepts)

##############################################################################
# Setup include paths. More include paths can be added in subdirectories.
##############################################################################
set(Hana_ROOT ${gem_SOURCE_DIR}/hana)
find_package(Hana 1.0 REQUIRED)
if(Hana_FOUND)
    include_directories(${Hana_INCLUDE_DIRS})
elseif()
    # todo: remove Hana required and use package download
endif()

set(Cereal_ROOT ${gem_SOURCE_DIR}/cereal)
find_package(Cereal REQUIRED)
if(CEREAL_FOUND)
    include_directories(${CEREAL_INCLUDE_DIRS})
elseif()
    # todo: remove Cereal required and use package download
endif()
MESSAGE(${gem_SOURCE_DIR}/include)
include_directories(${gem_SOURCE_DIR}/include)

add_library(gem INTERFACE)
target_sources(gem INTERFACE ${includes})

# target_compile_features(gem
#     INTERFACE cxx_auto_type
#     INTERFACE cxx_variadic_templates)

##############################################################################
# Setup custom functions to ease the creation of targets
##############################################################################
#   gem_target_name_for(<output variable> <source file> [ext])
#
# Return the target name associated to a source file. If the path of the
# source file relative from the root of Hana is `path/to/source/file.ext`,
# the target name associated to it will be `path.to.source.file`.
#
# The extension of the file should be specified as a last argument. If no
# extension is specified, the `.cpp` extension is assumed.
function(gem_target_name_for out file)
    if (NOT ARGV2)
        set(_extension ".cpp")
    else()
        set(_extension "${ARGV2}")
    endif()

    file(RELATIVE_PATH _relative ${PROJECT_SOURCE_DIR} ${file})
    string(REPLACE "${_extension}" "" _name ${_relative})
    string(REGEX REPLACE "/" "." _name ${_name})
    set(${out} "${_name}" PARENT_SCOPE)
endfunction()

#   gem_add_test(<name> <command> [<arg>...])
#
# Creates a test called `name`, which runs the given `command` with the given
# `arg`uments. However, if `GEM_ENABLE_MEMCHECK` is set to `ON`, the
# test will run the provided command under the memory checker.
if (GEM_ENABLE_MEMCHECK)
    find_package(Valgrind REQUIRED)
    function(gem_add_test name)
        add_test(${name} ${Valgrind_EXECUTABLE}
                 --suppressions=${PROJECT_SOURCE_DIR}/cmake/valgrind.supp
                 --leak-check=full --error-exitcode=1 ${ARGN})
    endfunction()
else()
    function(gem_add_test name)
        add_test(${name} ${ARGN})
    endfunction()
endif()

##############################################################################
# Setup the `check` target to build and then run all the tests and examples.
##############################################################################
add_custom_target(check
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Build and then run all the tests and examples.")

##############################################################################
# Setup subdirectories
##############################################################################
enable_testing()
add_subdirectory(doc)
add_subdirectory(tests)

##############################################################################
# Setup the 'install' target.
# This copies the whole content of include/ to ${CMAKE_INSTALL_PREFIX}.
##############################################################################
install(DIRECTORY include/ DESTINATION include/
        PATTERN ".DS_Store" EXCLUDE)

# We also install an optional pkg-config file.
# configure_file(cmake/hana.pc.in hana.pc @ONLY)
# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/hana.pc DESTINATION lib/pkgconfig)

##############################################################################
# Setup the 'uninstall' target.
# This removes the whole content of include/ to ${CMAKE_INSTALL_PREFIX}.
##############################################################################
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P
            ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
