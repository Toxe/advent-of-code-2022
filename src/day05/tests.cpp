#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "day05.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "    [D]",
        "[N] [C]",
        "[Z] [M] [P]",
        " 1   2   3",
        "",
        "move 1 from 2 to 1",
        "move 3 from 1 to 3",
        "move 2 from 2 to 1",
        "move 1 from 1 to 2",
    };

    SECTION("part 1")
    {
        CHECK_THAT(day05_part1(lines), Catch::Matchers::Equals("CMZ"));
    }

    SECTION("part 2")
    {
        CHECK_THAT(day05_part2(lines), Catch::Matchers::Equals("MCD"));
    }
}

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day05"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_preserve_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(day05_part1(input) == "PSNRGBTFT");
    }

    SECTION("part 2")
    {
        CHECK(day05_part2(input) == "BNTZFPMMW");
    }
}
