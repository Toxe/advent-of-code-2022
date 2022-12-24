add_executable(day01 main.cpp day01.cpp day01.hpp)

set_target_properties(day01 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day01 PUBLIC cxx_std_20)
target_compile_options(day01 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day01 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day01 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)
