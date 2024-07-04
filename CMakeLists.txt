cmake_minimum_required(VERSION 3.23)
project(AED_SCHEDULE)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_SCHEDULE main.cpp src/Headers/bst.h src/Implementation/UC.cpp src/Headers/UC.h src/Implementation/Student.cpp src/Headers/Student.h src/Implementation/Interval.cpp src/Headers/Interval.h src/Implementation/Schedule.cpp src/Headers/Schedule.h src/Headers/LoadData.h src/Implementation/LoadData.cpp src/Implementation/Menu.cpp src/Headers/Menu.h src/Headers/Request.h src/Implementation/Request.cpp)

# Doxygen Build
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if (NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif (DOXYGEN_FOUND)