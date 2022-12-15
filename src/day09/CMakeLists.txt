add_executable(day09 main.cpp day09.cpp day09.hpp)

set_target_properties(day09 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day09 PUBLIC cxx_std_20)
target_compile_options(day09 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day09 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day09 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)

# Tests
if (BUILD_TESTING)
    add_executable(day09_tests tests.cpp day09.cpp day09.hpp)

    set_target_properties(day09_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(day09_tests PUBLIC cxx_std_20)
    target_compile_options(day09_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(day09_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(day09_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc Catch2::Catch2WithMain)

    add_test(NAME day09_tests COMMAND day09_tests)
endif ()
