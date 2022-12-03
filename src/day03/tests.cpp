#include "catch2/catch_test_macros.hpp"

#include "day03.hpp"

TEST_CASE("part 1")
{
    SECTION("works with example input")
    {
        const std::vector<std::string> lines = {
            "vJrwpWtwJgWrhcsFMMfFFhFp",
            "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
            "PmmdzqPrVvPwwTWBwg",
            "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
            "ttgJtRGJQctTZtZT",
            "CrZsJsPPZsGzwwsLwLmpwMDw"};

        CHECK(day03_part1(lines) == 157);
    }
}

TEST_CASE("part 2")
{
    SECTION("works with example input")
    {
        const std::vector<std::string> lines = {
            "vJrwpWtwJgWrhcsFMMfFFhFp",
            "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
            "PmmdzqPrVvPwwTWBwg",
            "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
            "ttgJtRGJQctTZtZT",
            "CrZsJsPPZsGzwwsLwLmpwMDw"};

        CHECK(day03_part2(lines) == 70);
    }
}
