add_library(libday08 day08.cpp day08.hpp)
set_target_properties(libday08 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(libday08 PUBLIC cxx_std_20)
target_compile_options(libday08 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(libday08 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(libday08 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)

add_executable(day08 main.cpp)
set_target_properties(day08 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day08 PUBLIC cxx_std_20)
target_compile_options(day08 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day08 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day08 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc libday08)
