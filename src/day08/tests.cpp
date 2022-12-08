#include "catch2/catch_test_macros.hpp"

#include "day08.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "30373",
        "25512",
        "65332",
        "33549",
        "35390",
    };

    SECTION("part 1")
    {
        CHECK(day08_part1(lines) == 21);
    }

    SECTION("part 2")
    {
        CHECK(day08_part2(lines) == 8);
    }
}
