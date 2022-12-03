#include "catch2/catch_test_macros.hpp"

#include "day02.hpp"

TEST_CASE("part 1")
{
    SECTION("works with example input")
    {
        const std::vector<std::string> lines = {
            "A Y",
            "B X",
            "C Z"};

        CHECK(day02_part1(lines) == 15);
    }
}

TEST_CASE("part 2")
{
    SECTION("works with example input")
    {
        const std::vector<std::string> lines = {
            "A Y",
            "B X",
            "C Z"};

        CHECK(day02_part2(lines) == 12);
    }
}
