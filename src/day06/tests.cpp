#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "day06.hpp"

TEST_CASE("works with example input")
{
    SECTION("part 1")
    {
        CHECK(day06_part1("mjqjpqmgbljsphdztnvjfqwrcgsmlb") == 7);
        CHECK(day06_part1("bvwbjplbgvbhsrlpgdmjqwftvncz") == 5);
        CHECK(day06_part1("nppdvjthqldpwncqszvftbrmjlhg") == 6);
        CHECK(day06_part1("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg") == 10);
        CHECK(day06_part1("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw") == 11);
    }

    SECTION("part 2")
    {
        CHECK(day06_part2("mjqjpqmgbljsphdztnvjfqwrcgsmlb") == 19);
        CHECK(day06_part2("bvwbjplbgvbhsrlpgdmjqwftvncz") == 23);
        CHECK(day06_part2("nppdvjthqldpwncqszvftbrmjlhg") == 23);
        CHECK(day06_part2("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg") == 29);
        CHECK(day06_part2("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw") == 26);
    }
}

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day06"));
    REQUIRE(input_stream.has_value());
    const std::string line = read_single_line(*input_stream);

    SECTION("part 1")
    {
        CHECK(day06_part1(line) == 1210);
    }

    SECTION("part 2")
    {
        CHECK(day06_part2(line) == 3476);
    }
}
