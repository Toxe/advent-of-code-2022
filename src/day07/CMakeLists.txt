add_executable(day07 main.cpp day07.cpp day07.hpp)

set_target_properties(day07 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day07 PUBLIC cxx_std_20)
target_compile_options(day07 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day07 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day07 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)

# Tests
if (BUILD_TESTING)
    add_executable(day07_tests tests.cpp day07.cpp day07.hpp)

    set_target_properties(day07_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(day07_tests PUBLIC cxx_std_20)
    target_compile_options(day07_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(day07_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(day07_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc Catch2::Catch2WithMain)

    add_test(NAME day07_tests COMMAND day07_tests)
endif ()
