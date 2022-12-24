add_executable(day02 main.cpp day02.cpp day02.hpp)

set_target_properties(day02 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day02 PUBLIC cxx_std_20)
target_compile_options(day02 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day02 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day02 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)
