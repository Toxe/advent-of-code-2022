add_library(libday06 day06.cpp day06.hpp)
set_target_properties(libday06 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(libday06 PUBLIC cxx_std_20)
target_compile_options(libday06 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(libday06 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(libday06 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc)

add_executable(day06 main.cpp)
set_target_properties(day06 PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(day06 PUBLIC cxx_std_20)
target_compile_options(day06 PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(day06 PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(day06 PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc libday06)
