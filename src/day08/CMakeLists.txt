add_executable(day08 main.cpp day08.cpp day08.hpp)

set_target_properties(day08 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day08 PUBLIC cxx_std_20)
target_compile_options(day08 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day08 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day08 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)

# Tests
if (BUILD_TESTING)
    add_executable(day08_tests tests.cpp day08.cpp day08.hpp)

    set_target_properties(day08_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(day08_tests PUBLIC cxx_std_20)
    target_compile_options(day08_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(day08_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(day08_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc Catch2::Catch2WithMain)

    add_test(NAME day08_tests COMMAND day08_tests)
endif ()
