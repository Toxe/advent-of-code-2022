#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "../src/day04/day04.hpp"

TEST_CASE("day 04")
{
    SECTION("works with example input")
    {
        const std::vector<std::string> lines = {
            "2-4,6-8",
            "2-3,4-5",
            "5-7,7-9",
            "2-8,3-7",
            "6-6,4-6",
            "2-6,4-8",
        };

        SECTION("part 1")
        {
            CHECK(day04_part1(lines) == 2);
        }

        SECTION("part 2")
        {
            CHECK(day04_part2(lines) == 4);
        }
    }

    SECTION("works with puzzle input")
    {
        auto input_stream = open_input_file(find_input_file("day04"));
        REQUIRE(input_stream.has_value());
        const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

        SECTION("part 1")
        {
            CHECK(day04_part1(input) == 471);
        }

        SECTION("part 2")
        {
            CHECK(day04_part2(input) == 888);
        }
    }
}
