add_library(LIB_shared
        read_grouped_numbers.cpp
        read_grouped_numbers.hpp
        read_input.cpp
        read_input.hpp
        test_helpers.cpp
        test_helpers.hpp
)

set_target_properties(LIB_shared PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(LIB_shared PUBLIC cxx_std_20)
target_compile_options(LIB_shared PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(LIB_shared PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(LIB_shared PRIVATE ${SANITIZER_LINK_LIBRARIES})
target_include_directories(LIB_shared INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Tests
if (BUILD_TESTING)
    add_executable(lib_shared_tests
            read_grouped_numbers.test.cpp
            read_input.test.cpp
            test_helpers.test.cpp
    )

    set_target_properties(lib_shared_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(lib_shared_tests PUBLIC cxx_std_20)
    target_compile_options(lib_shared_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(lib_shared_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(lib_shared_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared Catch2::Catch2WithMain)

    add_test(NAME lib_shared_tests COMMAND lib_shared_tests)
endif ()
