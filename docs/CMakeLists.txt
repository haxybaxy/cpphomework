# docs/CMakeLists.txt

find_package(Doxygen REQUIRED)

# Directories to look for header files (.h) for the documentation
set(DOXYGEN_INCLUDE_PATHS ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)

# These variables will be used to configure Doxyfile.in into the final Doxyfile
string(REPLACE ";" " " DOXYGEN_INPUT_DIR "${DOXYGEN_INCLUDE_PATHS}")

set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)
set(DOXYGEN_XML_OUTPUT_DIR ${DOXYGEN_OUTPUT_DIR}/xml)
set(DOXYGEN_INDEX_FILE ${DOXYGEN_XML_OUTPUT_DIR}/index.xml)

# Ensure HTML and LaTeX generation are disabled
set(DOXYGEN_GENERATE_HTML NO)
set(DOXYGEN_GENERATE_LATEX NO)

# Path to the Doxyfile template (ensure this is a template with placeholders)
set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# Configure the Doxyfile
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

# Doxygen won't create this for us
file(MAKE_DIRECTORY ${DOXYGEN_XML_OUTPUT_DIR})

# Glob all .h files inside the directories listed in DOXYGEN_INCLUDE_DIRS to set them as dependencies
set(PUBLIC_HEADERS "")
foreach(dir ${DOXYGEN_INCLUDE_PATHS})
  file(GLOB_RECURSE CURRENT_HEADERS ${dir}/*.h)
  list(APPEND PUBLIC_HEADERS ${CURRENT_HEADERS})
endforeach()

# Add a custom target to run Doxygen when the project is built
add_custom_command(OUTPUT ${DOXYGEN_INDEX_FILE}
    DEPENDS ${PUBLIC_HEADERS} ${DOXYFILE_OUT}
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
    COMMENT "Generating Doxygen documentation"
    VERBATIM)

add_custom_target(Doxygen ALL DEPENDS ${DOXYGEN_INDEX_FILE})

# Add a custom target to generate the documentation with Sphinx
set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/sphinx)
add_custom_target(Sphinx ALL
                  COMMAND
                  ${CMAKE_COMMAND} -E env
                  AUTHOR_NAME=${PROJECT_AUTHOR}
                  PROJECT_NAME=${PROJECT_NAME}
                  sphinx-build -b html
                  -D breathe_projects.${PROJECT_NAME}=${DOXYGEN_XML_OUTPUT_DIR}
                  ${SPHINX_SOURCE} ${SPHINX_BUILD}
                  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                  COMMENT "Generating documentation with Sphinx"
                  DEPENDS ${DOXYGEN_INDEX_FILE})
