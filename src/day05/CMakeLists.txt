add_executable(day05 main.cpp day05.cpp day05.hpp)

set_target_properties(day05 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day05 PUBLIC cxx_std_20)
target_compile_options(day05 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day05 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day05 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)
