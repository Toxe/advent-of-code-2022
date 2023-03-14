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
    target_link_libraries(tests PRIVATE ${SANITIZER_LINK_LIBRARIES} Catch2::Catch2WithMain libaoc libday01 libday02 libday03 libday04 libday05 libday06 libday07 libday08 libday09 libday10)

    add_test(NAME tests COMMAND tests)
endif()
