#include <sstream>

#include "catch2/catch_test_macros.hpp"

#include "read_grid.hpp"
#include "read_input.hpp"
#include "test_helpers.hpp"

#include "../src/day08/day08.hpp"

TEST_CASE("day 08")
{
    SECTION("works with example input")
    {
        std::istringstream input{
            "30373\n"
            "25512\n"
            "65332\n"
            "33549\n"
            "35390\n"};

        const Grid grid = read_digit_grid(input);

        SECTION("part 1")
        {
            CHECK(day08_part1(grid) == 21);
        }

        SECTION("part 2")
        {
            CHECK(day08_part2(grid) == 8);
        }
    }

    SECTION("works with puzzle input")
    {
        auto input_stream = open_input_file(find_input_file("day08"));
        REQUIRE(input_stream.has_value());
        const Grid grid = read_digit_grid(*input_stream);

        SECTION("part 1")
        {
            CHECK(day08_part1(grid) == 1533);
        }

        SECTION("part 2")
        {
            CHECK(day08_part2(grid) == 345744);
        }
    }
}
