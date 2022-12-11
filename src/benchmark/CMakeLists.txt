add_executable(benchmark
        main.cpp
        ../day01/day01.cpp ../day01/day01.hpp
        ../day02/day02.cpp ../day02/day02.hpp
        ../day03/day03.cpp ../day03/day03.hpp
        ../day04/day04.cpp ../day04/day04.hpp
        ../day05/day05.cpp ../day05/day05.hpp
        ../day06/day06.cpp ../day06/day06.hpp
        ../day07/day07.cpp ../day07/day07.hpp
        ../day08/day08.cpp ../day08/day08.hpp
)

set_target_properties(benchmark PROPERTIES CXX_EXTENSIONS OFF)
target_compile_features(benchmark PUBLIC cxx_std_20)
target_compile_options(benchmark PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
target_link_options(benchmark PRIVATE ${SANITIZER_LINK_OPTIONS})
target_link_libraries(benchmark PRIVATE ${SANITIZER_LINK_LIBRARIES} LIB_shared benchmark::benchmark benchmark::benchmark_main)
