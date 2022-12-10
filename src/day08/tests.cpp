#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

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

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day08"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(day08_part1(input) == 1533);
    }

    SECTION("part 2")
    {
        CHECK(day08_part2(input) == 345744);
    }
}
