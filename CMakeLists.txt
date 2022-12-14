cmake_minimum_required(VERSION 3.22)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("Advent of Code 2022" LANGUAGES CXX)

# testing settings
include(cmake/Testing.cmake)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptions.cmake)
include(cmake/DefaultCompilerWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

find_package(fmt CONFIG REQUIRED)

add_subdirectory(src/libaoc)
add_subdirectory(src/day01)
add_subdirectory(src/day02)
add_subdirectory(src/day03)
add_subdirectory(src/day04)
add_subdirectory(src/day05)
add_subdirectory(src/day06)
add_subdirectory(src/day07)
add_subdirectory(src/day08)
add_subdirectory(src/day09)
add_subdirectory(src/day10)
add_subdirectory(src/benchmark)
add_subdirectory(tests)
