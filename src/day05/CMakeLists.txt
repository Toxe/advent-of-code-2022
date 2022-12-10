add_executable(day05 main.cpp day05.cpp day05.hpp)

set_target_properties(day05 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day05 PUBLIC cxx_std_20)
target_compile_options(day05 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day05 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day05 PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared)

# Tests
if (BUILD_TESTING)
    add_executable(day05_tests tests.cpp day05.cpp day05.hpp)

    set_target_properties(day05_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(day05_tests PUBLIC cxx_std_20)
    target_compile_options(day05_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(day05_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(day05_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared Catch2::Catch2WithMain)

    add_test(NAME day05_tests COMMAND day05_tests)
endif ()
