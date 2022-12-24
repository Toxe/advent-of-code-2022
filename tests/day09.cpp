#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "../src/day09/day09.hpp"

TEST_CASE("day 09: works with example input")
{
    SECTION("part 1")
    {
        const std::vector<std::string> lines = {
            "R 4",
            "U 4",
            "L 3",
            "D 1",
            "R 4",
            "D 1",
            "L 5",
            "R 2",
        };

        CHECK(day09_part1(lines) == 13);
    }

    SECTION("part 2")
    {
        const std::vector<std::string> lines1 = {
            "R 4",
            "U 4",
            "L 3",
            "D 1",
            "R 4",
            "D 1",
            "L 5",
            "R 2",
        };

        const std::vector<std::string> lines2 = {
            "R 5",
            "U 8",
            "L 8",
            "D 3",
            "R 17",
            "D 10",
            "L 25",
            "U 20",
        };

        CHECK(day09_part2(lines1) == 1);
        CHECK(day09_part2(lines2) == 36);
    }
}

TEST_CASE("day 09: works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day09"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(day09_part1(input) == 6209);
    }

    SECTION("part 2")
    {
        CHECK(day09_part2(input) == 2460);
    }
}
