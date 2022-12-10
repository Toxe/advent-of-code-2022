#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

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

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("dayDAYXX"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(dayDAYXX_part1(input) == -1);
    }

    SECTION("part 2")
    {
        CHECK(dayDAYXX_part2(input) == -1);
    }
}
