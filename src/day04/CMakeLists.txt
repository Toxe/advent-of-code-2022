add_executable(day04 main.cpp day04.cpp day04.hpp)

set_target_properties(day04 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day04 PUBLIC cxx_std_20)
target_compile_options(day04 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day04 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day04 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)
