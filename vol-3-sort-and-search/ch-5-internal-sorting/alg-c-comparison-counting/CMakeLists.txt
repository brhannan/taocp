cmake_minimum_required(VERSION 3.14)
project(comparison_count)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

enable_testing()
include(GoogleTest)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(
    "${PROJECT_SOURCE_DIR}/../../../googletest"
    "googletest"
    )
add_subdirectory(test)