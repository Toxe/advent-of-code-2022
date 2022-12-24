add_executable(dayDAYXX main.cpp dayDAYXX.cpp dayDAYXX.hpp)

set_target_properties(dayDAYXX PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(dayDAYXX PUBLIC cxx_std_20)
target_compile_options(dayDAYXX PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(dayDAYXX PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(dayDAYXX PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)
