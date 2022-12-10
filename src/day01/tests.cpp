#include "catch2/catch_test_macros.hpp"

#include "read_grouped_numbers.hpp"
#include "read_input.hpp"
#include "test_helpers.hpp"

#include "day01.hpp"

TEST_CASE("works with example input")
{
    const GroupedNumbers grouped_numbers = {
        {1000, 2000, 3000},
        {4000},
        {5000, 6000},
        {7000, 8000, 9000},
        {10000},
    };

    SECTION("part 1")
    {
        CHECK(day01_part1(grouped_numbers) == 24000);
    }

    SECTION("part 2")
    {
        CHECK(day01_part2(grouped_numbers) == 45000);
    }
}

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day01"));
    REQUIRE(input_stream.has_value());
    const GroupedNumbers grouped_numbers = read_grouped_numbers(*input_stream);

    SECTION("part 1")
    {
        CHECK(day01_part1(grouped_numbers) == 68775);
    }

    SECTION("part 2")
    {
        CHECK(day01_part2(grouped_numbers) == 202585);
    }
}
