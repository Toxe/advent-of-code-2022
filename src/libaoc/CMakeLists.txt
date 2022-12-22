add_library(libaoc
        coords.cpp
        coords.hpp
        grid.hpp
        gridcell.hpp
        print_results.cpp
        print_results.hpp
        read_grid.cpp
        read_grid.hpp
        read_grouped_numbers.cpp
        read_grouped_numbers.hpp
        read_input.cpp
        read_input.hpp
        test_helpers.cpp
        test_helpers.hpp
)

set_target_properties(libaoc PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(libaoc PUBLIC cxx_std_20)
target_compile_options(libaoc PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(libaoc PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(libaoc PRIVATE ${SANITIZER_LINK_LIBRARIES} fmt::fmt)
target_include_directories(libaoc INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" OR (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    target_compile_options(libaoc PUBLIC /D_CRT_SECURE_NO_WARNINGS)
endif ()

# Tests
if (BUILD_TESTING)
    add_executable(libaoc_tests
            coords.test.cpp
            grid.test.cpp
            gridcell.test.cpp
            read_grouped_numbers.test.cpp
            read_grid.test.cpp
            read_input.test.cpp
            test_helpers.test.cpp
    )

    set_target_properties(libaoc_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(libaoc_tests PUBLIC cxx_std_20)
    target_compile_options(libaoc_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(libaoc_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(libaoc_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc Catch2::Catch2WithMain)

    add_test(NAME libaoc_tests COMMAND libaoc_tests)
endif ()
