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
file(GLOB_RECURSE UNIT_TESTS "*.cpp")

foreach(_file IN LISTS UNIT_TESTS)
    gem_target_name_for(_target "${_file}")
    file(STRINGS "${_file}" _subparts REGEX "gem_TEST_PART == ([0-9]+)")

    # If the file contains the special gem_TEST_PART marker, we split
    # it into several subparts. This is done to avoid long compile-times and
    # other inconveniences.
    if (_subparts)
        string(REGEX MATCHALL "gem_TEST_PART == ([0-9]+)" _subparts "${_subparts}")
        string(REGEX REPLACE "gem_TEST_PART == ([0-9]+)" "\\1" _subparts "${_subparts}")
        list(REMOVE_DUPLICATES _subparts)
        add_custom_target(${_target})

        foreach(n IN LISTS _subparts)
            add_executable("${_target}.part${n}" EXCLUDE_FROM_ALL "${_file}")
            set_target_properties("${_target}.part${n}" PROPERTIES
                COMPILE_DEFINITIONS "gem_TEST_PART=${n}")
            add_dependencies(${_target} "${_target}.part${n}")

            gem_add_unit_test("${_target}.part${n}"
                ${CMAKE_CURRENT_BINARY_DIR}/${_target}.part${n})
        endforeach()
    else()
        add_executable(${_target} EXCLUDE_FROM_ALL "${_file}")
        gem_add_unit_test(${_target} ${CMAKE_CURRENT_BINARY_DIR}/${_target})
    endif()
endforeach()