#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "../src/day03/day03.hpp"

TEST_CASE("day 03: works with example input")
{
    const std::vector<std::string> lines = {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg",
        "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
        "ttgJtRGJQctTZtZT",
        "CrZsJsPPZsGzwwsLwLmpwMDw",
    };

    SECTION("part 1")
    {
        CHECK(day03_part1(lines) == 157);
    }

    SECTION("part 2")
    {
        CHECK(day03_part2(lines) == 70);
    }
}

TEST_CASE("day 03: works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day03"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(day03_part1(input) == 8240);
    }

    SECTION("part 2")
    {
        CHECK(day03_part2(input) == 2587);
    }
}
