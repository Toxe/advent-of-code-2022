#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "day10.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "addx 15",
        "addx -11",
        "addx 6",
        "addx -3",
        "addx 5",
        "addx -1",
        "addx -8",
        "addx 13",
        "addx 4",
        "noop",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx -35",
        "addx 1",
        "addx 24",
        "addx -19",
        "addx 1",
        "addx 16",
        "addx -11",
        "noop",
        "noop",
        "addx 21",
        "addx -15",
        "noop",
        "noop",
        "addx -3",
        "addx 9",
        "addx 1",
        "addx -3",
        "addx 8",
        "addx 1",
        "addx 5",
        "noop",
        "noop",
        "noop",
        "noop",
        "noop",
        "addx -36",
        "noop",
        "addx 1",
        "addx 7",
        "noop",
        "noop",
        "noop",
        "addx 2",
        "addx 6",
        "noop",
        "noop",
        "noop",
        "noop",
        "noop",
        "addx 1",
        "noop",
        "noop",
        "addx 7",
        "addx 1",
        "noop",
        "addx -13",
        "addx 13",
        "addx 7",
        "noop",
        "addx 1",
        "addx -33",
        "noop",
        "noop",
        "noop",
        "addx 2",
        "noop",
        "noop",
        "noop",
        "addx 8",
        "noop",
        "addx -1",
        "addx 2",
        "addx 1",
        "noop",
        "addx 17",
        "addx -9",
        "addx 1",
        "addx 1",
        "addx -3",
        "addx 11",
        "noop",
        "noop",
        "addx 1",
        "noop",
        "addx 1",
        "noop",
        "noop",
        "addx -13",
        "addx -19",
        "addx 1",
        "addx 3",
        "addx 26",
        "addx -30",
        "addx 12",
        "addx -1",
        "addx 3",
        "addx 1",
        "noop",
        "noop",
        "noop",
        "addx -9",
        "addx 18",
        "addx 1",
        "addx 2",
        "noop",
        "noop",
        "addx 9",
        "noop",
        "noop",
        "noop",
        "addx -1",
        "addx 2",
        "addx -37",
        "addx 1",
        "addx 3",
        "noop",
        "addx 15",
        "addx -21",
        "addx 22",
        "addx -6",
        "addx 1",
        "noop",
        "addx 2",
        "addx 1",
        "noop",
        "addx -10",
        "noop",
        "noop",
        "addx 20",
        "addx 1",
        "addx 2",
        "addx 2",
        "addx -6",
        "addx -11",
        "noop",
        "noop",
        "noop",
    };

    SECTION("part 1")
    {
        CHECK(day10_part1(lines) == 13140);
    }

    SECTION("part 2")
    {
        const std::string result = "##..##..##..##..##..##..##..##..##..##..\n"
                                   "###...###...###...###...###...###...###.\n"
                                   "####....####....####....####....####....\n"
                                   "#####.....#####.....#####.....#####.....\n"
                                   "######......######......######......####\n"
                                   "#######.......#######.......#######.....\n";

        CHECK_THAT(day10_part2(lines), Catch::Matchers::Equals(result));
    }
}

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day10"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(day10_part1(input) == 13760);
    }

    SECTION("part 2")
    {
        const std::string result = "###..####.#..#.####..##..###..####.####.\n"
                                   "#..#.#....#.#.....#.#..#.#..#.#....#....\n"
                                   "#..#.###..##.....#..#....#..#.###..###..\n"
                                   "###..#....#.#...#...#....###..#....#....\n"
                                   "#.#..#....#.#..#....#..#.#....#....#....\n"
                                   "#..#.#....#..#.####..##..#....####.#....\n";

        CHECK_THAT(day10_part2(input), Catch::Matchers::Equals(result));
    }
}
