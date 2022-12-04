#include "catch2/catch_test_macros.hpp"

#include "day02.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "A Y",
        "B X",
        "C Z"};

    SECTION("part 1")
    {
        CHECK(day02_part1(lines) == 15);
    }

    SECTION("part 2")
    {
        CHECK(day02_part2(lines) == 12);
    }
}
