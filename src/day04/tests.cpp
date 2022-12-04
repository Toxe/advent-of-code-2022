#include "catch2/catch_test_macros.hpp"

#include "day04.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "2-4,6-8",
        "2-3,4-5",
        "5-7,7-9",
        "2-8,3-7",
        "6-6,4-6",
        "2-6,4-8"};

    SECTION("part 1")
    {
        CHECK(day04_part1(lines) == 2);
    }

    SECTION("part 2")
    {
        CHECK(day04_part2(lines) == 4);
    }
}
