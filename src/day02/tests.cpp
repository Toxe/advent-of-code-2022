#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "day02.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "A Y",
        "B X",
        "C Z",
    };

    SECTION("part 1")
    {
        CHECK(day02_part1(lines) == 15);
    }

    SECTION("part 2")
    {
        CHECK(day02_part2(lines) == 12);
    }
}

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day02"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(day02_part1(input) == 13005);
    }

    SECTION("part 2")
    {
        CHECK(day02_part2(input) == 11373);
    }
}
