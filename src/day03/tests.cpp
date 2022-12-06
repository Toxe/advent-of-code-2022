#include "catch2/catch_test_macros.hpp"

#include "day03.hpp"

TEST_CASE("works with example input")
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
