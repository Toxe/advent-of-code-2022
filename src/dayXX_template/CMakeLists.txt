add_executable(dayDAYXX main.cpp dayDAYXX.cpp dayDAYXX.hpp)

set_target_properties(dayDAYXX PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(dayDAYXX PUBLIC cxx_std_20)
target_compile_options(dayDAYXX PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(dayDAYXX PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(dayDAYXX PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared)

# Tests
if (BUILD_TESTING)
    add_executable(dayDAYXX_tests tests.cpp dayDAYXX.cpp dayDAYXX.hpp)

    set_target_properties(dayDAYXX_tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(dayDAYXX_tests PUBLIC cxx_std_20)
    target_compile_options(dayDAYXX_tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(dayDAYXX_tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(dayDAYXX_tests PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared Catch2::Catch2WithMain)

    add_test(NAME dayDAYXX_tests COMMAND dayDAYXX_tests)
endif ()
