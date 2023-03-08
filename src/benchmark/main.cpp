#include <cassert>
#include <fstream>

#define ANKERL_NANOBENCH_IMPLEMENT
#include "nanobench.h"

#include "read_grid.hpp"
#include "read_grouped_numbers.hpp"
#include "read_input.hpp"
#include "test_helpers.hpp"

#include "../day01/day01.hpp"
#include "../day02/day02.hpp"
#include "../day03/day03.hpp"
#include "../day04/day04.hpp"
#include "../day05/day05.hpp"
#include "../day06/day06.hpp"
#include "../day07/day07.hpp"
#include "../day08/day08.hpp"
#include "../day09/day09.hpp"
#include "../day10/day10.hpp"

void example_input_day01()
{
    const GroupedNumbers grouped_numbers = {
        {1000, 2000, 3000},
        {4000},
        {5000, 6000},
        {7000, 8000, 9000},
        {10000},
    };

    ankerl::nanobench::Bench().run("example input: day 01, part 1", [&] {
        const auto result = day01_part1(grouped_numbers);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 24000);
    });

    ankerl::nanobench::Bench().run("example input: day 01, part 2", [&] {
        const auto result = day01_part2(grouped_numbers);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 45000);
    });
}

void example_input_day02()
{
    const std::vector<std::string> lines = {
        "A Y",
        "B X",
        "C Z",
    };

    ankerl::nanobench::Bench().run("example input: day 02, part 1", [&] {
        const auto result = day02_part1(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 15);
    });

    ankerl::nanobench::Bench().run("example input: day 02, part 2", [&] {
        const auto result = day02_part2(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 12);
    });
}

void example_input_day03()
{
    const std::vector<std::string> lines = {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg",
        "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
        "ttgJtRGJQctTZtZT",
        "CrZsJsPPZsGzwwsLwLmpwMDw",
    };

    ankerl::nanobench::Bench().run("example input: day 03, part 1", [&] {
        const auto result = day03_part1(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 157);
    });

    ankerl::nanobench::Bench().run("example input: day 03, part 2", [&] {
        const auto result = day03_part2(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 70);
    });
}

void example_input_day04()
{
    const std::vector<std::string> lines = {
        "2-4,6-8",
        "2-3,4-5",
        "5-7,7-9",
        "2-8,3-7",
        "6-6,4-6",
        "2-6,4-8",
    };

    ankerl::nanobench::Bench().run("example input: day 04, part 1", [&] {
        const auto result = day04_part1(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 2);
    });

    ankerl::nanobench::Bench().run("example input: day 04, part 2", [&] {
        const auto result = day04_part2(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 4);
    });
}

void example_input_day05()
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

    ankerl::nanobench::Bench().run("example input: day 05, part 1", [&] {
        const auto result = day05_part1(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == "CMZ");
    });

    ankerl::nanobench::Bench().run("example input: day 05, part 2", [&] {
        const auto result = day05_part2(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == "MCD");
    });
}

void example_input_day06()
{
    ankerl::nanobench::Bench().run("example input: day 06, part 1", [&] {
        const auto result1 = day06_part1("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
        const auto result2 = day06_part1("bvwbjplbgvbhsrlpgdmjqwftvncz");
        const auto result3 = day06_part1("nppdvjthqldpwncqszvftbrmjlhg");
        const auto result4 = day06_part1("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg");
        const auto result5 = day06_part1("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw");

        ankerl::nanobench::doNotOptimizeAway(result1);
        ankerl::nanobench::doNotOptimizeAway(result2);
        ankerl::nanobench::doNotOptimizeAway(result3);
        ankerl::nanobench::doNotOptimizeAway(result4);
        ankerl::nanobench::doNotOptimizeAway(result5);

        assert(result1 == 7);
        assert(result2 == 5);
        assert(result3 == 6);
        assert(result4 == 10);
        assert(result5 == 11);
    });

    ankerl::nanobench::Bench().run("example input: day 06, part 2", [&] {
        const auto result1 = day06_part2("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
        const auto result2 = day06_part2("bvwbjplbgvbhsrlpgdmjqwftvncz");
        const auto result3 = day06_part2("nppdvjthqldpwncqszvftbrmjlhg");
        const auto result4 = day06_part2("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg");
        const auto result5 = day06_part2("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw");

        ankerl::nanobench::doNotOptimizeAway(result1);
        ankerl::nanobench::doNotOptimizeAway(result2);
        ankerl::nanobench::doNotOptimizeAway(result3);
        ankerl::nanobench::doNotOptimizeAway(result4);
        ankerl::nanobench::doNotOptimizeAway(result5);

        assert(result1 == 19);
        assert(result2 == 23);
        assert(result3 == 23);
        assert(result4 == 29);
        assert(result5 == 26);
    });
}

void example_input_day07()
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

    ankerl::nanobench::Bench().run("example input: day 07, part 1", [&] {
        const auto result = day07_part1(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 95437);
    });

    ankerl::nanobench::Bench().run("example input: day 07, part 2", [&] {
        const auto result = day07_part2(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 24933642);
    });
}

void example_input_day08()
{
    std::ofstream out1("example_input_day08_part1.json");
    std::ofstream out2("example_input_day08_part2.json");

    std::istringstream input{
        "30373\n"
        "25512\n"
        "65332\n"
        "33549\n"
        "35390\n"};

    const auto grid = read_digit_grid(input);

    ankerl::nanobench::Bench().epochs(1000).run("example input: day 08, part 1", [&] {
        const auto result = day08_part1(grid);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 21);
    }).render(ankerl::nanobench::templates::pyperf(), out1);

    ankerl::nanobench::Bench().epochs(1000).run("example input: day 08, part 2", [&] {
        const auto result = day08_part2(grid);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 8);
    }).render(ankerl::nanobench::templates::pyperf(), out2);
}

void example_input_day09()
{
    const std::vector<std::string> lines1 = {
        "R 4",
        "U 4",
        "L 3",
        "D 1",
        "R 4",
        "D 1",
        "L 5",
        "R 2",
    };

    const std::vector<std::string> lines2 = {
        "R 5",
        "U 8",
        "L 8",
        "D 3",
        "R 17",
        "D 10",
        "L 25",
        "U 20",
    };

    ankerl::nanobench::Bench().run("example input: day 09, part 1", [&] {
        const auto result = day09_part1(lines1);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 13);
    });

    ankerl::nanobench::Bench().run("example input: day 09, part 2", [&] {
        const auto result1 = day09_part2(lines1);
        const auto result2 = day09_part2(lines2);

        ankerl::nanobench::doNotOptimizeAway(result1);
        ankerl::nanobench::doNotOptimizeAway(result2);

        assert(result1 == 1);
        assert(result2 == 36);
    });
}

void example_input_day10()
{
    const std::vector<std::string> lines = {
        "addx 15",
        "addx -11",
        "addx 6",
        "addx -3",
        "addx 5",
        "addx -1",
        "addx -8",
        "addx 13",
        "addx 4",
        "noop",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx 5",
        "addx -1",
        "addx -35",
        "addx 1",
        "addx 24",
        "addx -19",
        "addx 1",
        "addx 16",
        "addx -11",
        "noop",
        "noop",
        "addx 21",
        "addx -15",
        "noop",
        "noop",
        "addx -3",
        "addx 9",
        "addx 1",
        "addx -3",
        "addx 8",
        "addx 1",
        "addx 5",
        "noop",
        "noop",
        "noop",
        "noop",
        "noop",
        "addx -36",
        "noop",
        "addx 1",
        "addx 7",
        "noop",
        "noop",
        "noop",
        "addx 2",
        "addx 6",
        "noop",
        "noop",
        "noop",
        "noop",
        "noop",
        "addx 1",
        "noop",
        "noop",
        "addx 7",
        "addx 1",
        "noop",
        "addx -13",
        "addx 13",
        "addx 7",
        "noop",
        "addx 1",
        "addx -33",
        "noop",
        "noop",
        "noop",
        "addx 2",
        "noop",
        "noop",
        "noop",
        "addx 8",
        "noop",
        "addx -1",
        "addx 2",
        "addx 1",
        "noop",
        "addx 17",
        "addx -9",
        "addx 1",
        "addx 1",
        "addx -3",
        "addx 11",
        "noop",
        "noop",
        "addx 1",
        "noop",
        "addx 1",
        "noop",
        "noop",
        "addx -13",
        "addx -19",
        "addx 1",
        "addx 3",
        "addx 26",
        "addx -30",
        "addx 12",
        "addx -1",
        "addx 3",
        "addx 1",
        "noop",
        "noop",
        "noop",
        "addx -9",
        "addx 18",
        "addx 1",
        "addx 2",
        "noop",
        "noop",
        "addx 9",
        "noop",
        "noop",
        "noop",
        "addx -1",
        "addx 2",
        "addx -37",
        "addx 1",
        "addx 3",
        "noop",
        "addx 15",
        "addx -21",
        "addx 22",
        "addx -6",
        "addx 1",
        "noop",
        "addx 2",
        "addx 1",
        "noop",
        "addx -10",
        "noop",
        "noop",
        "addx 20",
        "addx 1",
        "addx 2",
        "addx 2",
        "addx -6",
        "addx -11",
        "noop",
        "noop",
        "noop",
    };

    ankerl::nanobench::Bench().run("example input: day 10, part 1", [&] {
        const auto result = day10_part1(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 13140);
    });

    const std::string expected_result = "##..##..##..##..##..##..##..##..##..##..\n"
                                        "###...###...###...###...###...###...###.\n"
                                        "####....####....####....####....####....\n"
                                        "#####.....#####.....#####.....#####.....\n"
                                        "######......######......######......####\n"
                                        "#######.......#######.......#######.....\n";

    ankerl::nanobench::Bench().run("example input: day 10, part 2", [&] {
        const auto result = day10_part2(lines);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == expected_result);
    });
}

void puzzle_input_day01()
{
    auto input_stream = open_input_file(find_input_file("day01"));
    const GroupedNumbers grouped_numbers = read_grouped_numbers(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 01, part 1", [&] {
        const auto result = day01_part1(grouped_numbers);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 68775);
    });

    ankerl::nanobench::Bench().run("puzzle input: day 01, part 2", [&] {
        const auto result = day01_part2(grouped_numbers);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 202585);
    });
}

void puzzle_input_day02()
{
    auto input_stream = open_input_file(find_input_file("day02"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 02, part 1", [&] {
        const auto result = day02_part1(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 13005);
    });

    ankerl::nanobench::Bench().run("puzzle input: day 02, part 2", [&] {
        const auto result = day02_part2(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 11373);
    });
}

void puzzle_input_day03()
{
    auto input_stream = open_input_file(find_input_file("day03"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 03, part 1", [&] {
        const auto result = day03_part1(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 8240);
    });

    ankerl::nanobench::Bench().run("puzzle input: day 03, part 2", [&] {
        const auto result = day03_part2(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 2587);
    });
}

void puzzle_input_day04()
{
    auto input_stream = open_input_file(find_input_file("day04"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 04, part 1", [&] {
        const auto result = day04_part1(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 471);
    });

    ankerl::nanobench::Bench().run("puzzle input: day 04, part 2", [&] {
        const auto result = day04_part2(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 888);
    });
}

void puzzle_input_day05()
{
    auto input_stream = open_input_file(find_input_file("day05"));
    const std::vector<std::string> input = read_lines_and_preserve_empty_lines(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 05, part 1", [&] {
        const auto result = day05_part1(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == "PSNRGBTFT");
    });

    ankerl::nanobench::Bench().run("puzzle input: day 05, part 2", [&] {
        const auto result = day05_part2(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == "BNTZFPMMW");
    });
}

void puzzle_input_day06()
{
    auto input_stream = open_input_file(find_input_file("day06"));
    const std::string line = read_single_line(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 06, part 1", [&] {
        const auto result = day06_part1(line);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 1210);
    });

    ankerl::nanobench::Bench().run("puzzle input: day 06, part 2", [&] {
        const auto result = day06_part2(line);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 3476);
    });
}

void puzzle_input_day07()
{
    auto input_stream = open_input_file(find_input_file("day07"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 07, part 1", [&] {
        const auto result = day07_part1(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 1581595);
    });

    ankerl::nanobench::Bench().run("puzzle input: day 07, part 2", [&] {
        const auto result = day07_part2(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 1544176);
    });
}

void puzzle_input_day08()
{
    std::ofstream out1("puzzle_input_day08_part1.json");
    std::ofstream out2("puzzle_input_day08_part2.json");

    auto input_stream = open_input_file(find_input_file("day08"));
    const auto grid = read_digit_grid(*input_stream);

    ankerl::nanobench::Bench().epochs(1000).run("puzzle input: day 08, part 1", [&] {
        const auto result = day08_part1(grid);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 1533);
    }).render(ankerl::nanobench::templates::pyperf(), out1);

    ankerl::nanobench::Bench().epochs(1000).run("puzzle input: day 08, part 2", [&] {
        const auto result = day08_part2(grid);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 345744);
    }).render(ankerl::nanobench::templates::pyperf(), out2);
}

void puzzle_input_day09()
{
    auto input_stream = open_input_file(find_input_file("day09"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 09, part 1", [&] {
        const auto result = day09_part1(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 6209);
    });

    ankerl::nanobench::Bench().run("puzzle input: day 09, part 2", [&] {
        const auto result = day09_part2(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 2460);
    });
}

void puzzle_input_day10()
{
    auto input_stream = open_input_file(find_input_file("day10"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    ankerl::nanobench::Bench().run("puzzle input: day 10, part 1", [&] {
        const auto result = day10_part1(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == 13760);
    });

    const std::string expected_result = "###..####.#..#.####..##..###..####.####.\n"
                                        "#..#.#....#.#.....#.#..#.#..#.#....#....\n"
                                        "#..#.###..##.....#..#....#..#.###..###..\n"
                                        "###..#....#.#...#...#....###..#....#....\n"
                                        "#.#..#....#.#..#....#..#.#....#....#....\n"
                                        "#..#.#....#..#.####..##..#....####.#....\n";

    ankerl::nanobench::Bench().run("puzzle input: day 10, part 2", [&] {
        const auto result = day10_part2(input);
        ankerl::nanobench::doNotOptimizeAway(result);
        assert(result == expected_result);
    });
}

int main()
{
    example_input_day01();
    example_input_day02();
    example_input_day03();
    example_input_day04();
    example_input_day05();
    example_input_day06();
    example_input_day07();
    example_input_day08();
    example_input_day09();
    example_input_day10();

    puzzle_input_day01();
    puzzle_input_day02();
    puzzle_input_day03();
    puzzle_input_day04();
    puzzle_input_day05();
    puzzle_input_day06();
    puzzle_input_day07();
    puzzle_input_day08();
    puzzle_input_day09();
    puzzle_input_day10();
}
