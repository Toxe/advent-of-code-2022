find_path(NANOBENCH_INCLUDE_DIRS nanobench.h)

add_executable(benchmark main.cpp)
set_target_properties(benchmark PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(benchmark PUBLIC cxx_std_20)
target_compile_options(benchmark PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(benchmark PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(benchmark PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc libday01 libday02 libday03 libday04 libday05 libday06 libday07 libday08 libday09 libday10)
target_include_directories(benchmark PRIVATE ${NANOBENCH_INCLUDE_DIRS})
