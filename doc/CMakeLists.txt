# Copyright Louis Dionne 2013-2016
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

find_package(Doxygen)
if (NOT DOXYGEN_FOUND)
    message(WARNING "Doxygen was not found; the 'doc' and 'docset' targets "
                    "will be unavailable.")
    return()
endif()

set(GEM_HTML_OUTPUT       html)
set(GEM_GENERATE_DOCSET   NO)
set(GEM_GENERATE_TREEVIEW YES)
set(GEM_SEARCHENGINE      YES)
configure_file(Doxyfile.in documentation.doxygen @ONLY)
add_custom_target(doc
    COMMAND ${CMAKE_COMMAND} -E remove_directory html
    COMMAND ${DOXYGEN_EXECUTABLE} documentation.doxygen
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)

set(GEM_HTML_OUTPUT       _docset)
set(GEM_GENERATE_DOCSET   YES)
set(GEM_GENERATE_TREEVIEW NO)
set(GEM_SEARCHENGINE      NO)
configure_file(Doxyfile.in docset.doxygen @ONLY)
add_custom_target(docset
    COMMAND ${DOXYGEN_EXECUTABLE} docset.doxygen
    COMMAND ${CMAKE_COMMAND} -E chdir _docset make
    COMMAND ${CMAKE_COMMAND} -E remove_directory gem.docset
    COMMAND ${CMAKE_COMMAND} -E copy_directory _docset/gem.docset gem.docset
    COMMAND ${CMAKE_COMMAND} -E remove_directory _docset
    COMMENT "Generating documentation Docset"
    VERBATIM
)
