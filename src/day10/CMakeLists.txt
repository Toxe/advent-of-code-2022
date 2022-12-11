add_executable(day10 main.cpp day10.cpp day10.hpp)

set_target_properties(day10 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day10 PUBLIC cxx_std_20)
target_compile_options(day10 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day10 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day10 PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared)

# Tests
if (BUILD_TESTING)
    add_executable(day10_tests tests.cpp day10.cpp day10.hpp)

    set_target_properties(day10_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(day10_tests PUBLIC cxx_std_20)
    target_compile_options(day10_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(day10_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(day10_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared Catch2::Catch2WithMain)

    add_test(NAME day10_tests COMMAND day10_tests)
endif ()
