add_executable(day03 main.cpp day03.cpp day03.hpp)

set_target_properties(day03 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day03 PUBLIC cxx_std_20)
target_compile_options(day03 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day03 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day03 PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared)

# Tests
if (BUILD_TESTING)
    add_executable(day03_tests tests.cpp day03.cpp day03.hpp)

    set_target_properties(day03_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(day03_tests PUBLIC cxx_std_20)
    target_compile_options(day03_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(day03_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(day03_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain)

    add_test(NAME day03_tests COMMAND day03_tests)
endif ()
