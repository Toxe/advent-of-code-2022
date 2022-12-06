#include "catch2/catch_test_macros.hpp"

#include "dayDAYXX.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "line1",
        "line2",
    };

    SECTION("part 1")
    {
        CHECK(dayDAYXX_part1(lines) == -1);
    }

    SECTION("part 2")
    {
        CHECK(dayDAYXX_part2(lines) == -1);
    }
}
