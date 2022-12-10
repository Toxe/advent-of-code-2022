#include "catch2/catch_test_macros.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

#include "day07.hpp"

TEST_CASE("works with example input")
{
    const std::vector<std::string> lines = {
        "$ cd /",
        "$ ls",
        "dir a",
        "14848514 b.txt",
        "8504156 c.dat",
        "dir d",
        "$ cd a",
        "$ ls",
        "dir e",
        "29116 f",
        "2557 g",
        "62596 h.lst",
        "$ cd e",
        "$ ls",
        "584 i",
        "$ cd ..",
        "$ cd ..",
        "$ cd d",
        "$ ls",
        "4060174 j",
        "8033020 d.log",
        "5626152 d.ext",
        "7214296 k",
    };

    SECTION("part 1")
    {
        CHECK(day07_part1(lines) == 95437);
    }

    SECTION("part 2")
    {
        CHECK(day07_part2(lines) == 24933642);
    }
}

TEST_CASE("works with puzzle input")
{
    auto input_stream = open_input_file(find_input_file("day07"));
    REQUIRE(input_stream.has_value());
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    SECTION("part 1")
    {
        CHECK(day07_part1(input) == 1581595);
    }

    SECTION("part 2")
    {
        CHECK(day07_part2(input) == 1544176);
    }
}
