# Copyright Louis Dionne 2013-2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

##############################################################################
# Setup custom functions and master targets for the unit tests
##############################################################################
add_custom_target(tests COMMENT "Build all the unit tests.")
add_dependencies(check tests)

add_custom_target(tests.quick COMMENT
				  "Build a subset of all the unit tests to finish faster.")

#   gem_add_unit_test(<name> ...)
#
# Equivalent to `gem_add_test`, except the test is also added as a
# dependency of the `tests` target.
function(gem_add_unit_test name)
    gem_add_test(${ARGV})
    add_dependencies(tests ${name})
    if (NOT "${name}" MATCHES "\\.ext\\.|_mcd|\\.auto\\.")
        add_dependencies(tests.quick ${name})
    endif()
endfunction()

##############################################################################
# Include additional support directories
##############################################################################


##############################################################################
# Caveats: Take note of public headers and tests that are not supported.
##############################################################################


##############################################################################
# Generate tests that include each public header.
# The headers that were excluded above due to caveats are ignored here.
##############################################################################
file(GLOB_RECURSE PUBLIC_HEADERS
    RELATIVE "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
)

include(TestHeaders)
add_dependencies(tests.quick test.headers)
add_dependencies(tests test.headers)

##############################################################################
# Add all the remaining unit tests
##############################################################################
##############################################################################
file(GLOB_RECURSE UNIT_TESTS "*.cpp")

foreach(_file IN LISTS UNIT_TESTS)
    include(CodeCoverage)
    gem_target_name_for(_target "${_file}")
    add_executable(${_target} EXCLUDE_FROM_ALL "${_file}")
    target_include_directories(${_target} PRIVATE _include)
    gem_add_unit_test(${_target} ${CMAKE_CURRENT_BINARY_DIR}/${_target})
endforeach()
