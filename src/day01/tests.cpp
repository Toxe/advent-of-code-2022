#include "catch2/catch_test_macros.hpp"

#include "day01.hpp"

TEST_CASE("works with example input")
{
    const GroupedNumbers grouped_numbers = {
        {1000, 2000, 3000},
        {4000},
        {5000, 6000},
        {7000, 8000, 9000},
        {10000}};

    SECTION("part 1")
    {
        CHECK(day01_part1(grouped_numbers) == 24000);
    }

    SECTION("part 2")
    {
        CHECK(day01_part2(grouped_numbers) == 45000);
    }
}
