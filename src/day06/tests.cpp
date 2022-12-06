#include "catch2/catch_test_macros.hpp"

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
