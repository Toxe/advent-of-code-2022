if(BUILD_TESTING)
    add_executable(tests
        day01.cpp
        day02.cpp
        day03.cpp
        day04.cpp
        day05.cpp
        day06.cpp
        day07.cpp
        day08.cpp
        day09.cpp
        day10.cpp
        ../src/day01/day01.cpp
        ../src/day01/day01.hpp
        ../src/day02/day02.cpp
        ../src/day02/day02.hpp
        ../src/day03/day03.cpp
        ../src/day03/day03.hpp
        ../src/day04/day04.cpp
        ../src/day04/day04.hpp
        ../src/day05/day05.cpp
        ../src/day05/day05.hpp
        ../src/day06/day06.cpp
        ../src/day06/day06.hpp
        ../src/day07/day07.cpp
        ../src/day07/day07.hpp
        ../src/day08/day08.cpp
        ../src/day08/day08.hpp
        ../src/day09/day09.cpp
        ../src/day09/day09.hpp
        ../src/day10/day10.cpp
        ../src/day10/day10.hpp
        libaoc/coords.cpp
        libaoc/grid.cpp
        libaoc/gridcell.cpp
        libaoc/read_grid.cpp
        libaoc/read_grouped_numbers.cpp
        libaoc/read_input.cpp
        libaoc/test_helpers.cpp
    )

    set_target_properties(tests PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(tests PUBLIC cxx_std_20)
    target_compile_options(tests PRIVATE ${SANITIZER_COMPILE_OPTIONS} ${DEFAULT_COMPILER_OPTIONS} ${DEFAULT_COMPILER_WARNINGS})
    target_link_options(tests PRIVATE ${SANITIZER_LINK_OPTIONS})
    target_link_libraries(tests PRIVATE ${SANITIZER_LINK_LIBRARIES} libaoc Catch2::Catch2WithMain)

    add_test(NAME tests COMMAND tests)
endif()
