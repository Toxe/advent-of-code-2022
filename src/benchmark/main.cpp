#include <cassert>

#include "benchmark/benchmark.h"

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

static void BM_example_input_day01_part1(benchmark::State& state)
{
    const GroupedNumbers grouped_numbers = {
        {1000, 2000, 3000},
        {4000},
        {5000, 6000},
        {7000, 8000, 9000},
        {10000},
    };

    for (auto _ : state) {
        const auto result = day01_part1(grouped_numbers);
        benchmark::DoNotOptimize(result);
        assert(result == 24000);
    }
}

static void BM_example_input_day01_part2(benchmark::State& state)
{
    const GroupedNumbers grouped_numbers = {
        {1000, 2000, 3000},
        {4000},
        {5000, 6000},
        {7000, 8000, 9000},
        {10000},
    };

    for (auto _ : state) {
        const auto result = day01_part2(grouped_numbers);
        benchmark::DoNotOptimize(result);
        assert(result == 45000);
    }
}

static void BM_example_input_day02_part1(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "A Y",
        "B X",
        "C Z",
    };

    for (auto _ : state) {
        const auto result = day02_part1(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 15);
    }
}

static void BM_example_input_day02_part2(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "A Y",
        "B X",
        "C Z",
    };

    for (auto _ : state) {
        const auto result = day02_part2(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 12);
    }
}

static void BM_example_input_day03_part1(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg",
        "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
        "ttgJtRGJQctTZtZT",
        "CrZsJsPPZsGzwwsLwLmpwMDw",
    };

    for (auto _ : state) {
        const auto result = day03_part1(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 157);
    }
}

static void BM_example_input_day03_part2(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "vJrwpWtwJgWrhcsFMMfFFhFp",
        "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL",
        "PmmdzqPrVvPwwTWBwg",
        "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn",
        "ttgJtRGJQctTZtZT",
        "CrZsJsPPZsGzwwsLwLmpwMDw",
    };

    for (auto _ : state) {
        const auto result = day03_part2(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 70);
    }
}

static void BM_example_input_day04_part1(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "2-4,6-8",
        "2-3,4-5",
        "5-7,7-9",
        "2-8,3-7",
        "6-6,4-6",
        "2-6,4-8",
    };

    for (auto _ : state) {
        const auto result = day04_part1(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 2);
    }
}

static void BM_example_input_day04_part2(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "2-4,6-8",
        "2-3,4-5",
        "5-7,7-9",
        "2-8,3-7",
        "6-6,4-6",
        "2-6,4-8",
    };

    for (auto _ : state) {
        const auto result = day04_part2(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 4);
    }
}

static void BM_example_input_day05_part1(benchmark::State& state)
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

    for (auto _ : state) {
        const auto result = day05_part1(lines);
        benchmark::DoNotOptimize(result);
        assert(result == "CMZ");
    }
}

static void BM_example_input_day05_part2(benchmark::State& state)
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

    for (auto _ : state) {
        const auto result = day05_part2(lines);
        benchmark::DoNotOptimize(result);
        assert(result == "MCD");
    }
}

static void BM_example_input_day06_part1(benchmark::State& state)
{
    for (auto _ : state) {
        const auto result1 = day06_part1("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
        const auto result2 = day06_part1("bvwbjplbgvbhsrlpgdmjqwftvncz");
        const auto result3 = day06_part1("nppdvjthqldpwncqszvftbrmjlhg");
        const auto result4 = day06_part1("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg");
        const auto result5 = day06_part1("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw");

        benchmark::DoNotOptimize(result1);
        benchmark::DoNotOptimize(result2);
        benchmark::DoNotOptimize(result3);
        benchmark::DoNotOptimize(result4);
        benchmark::DoNotOptimize(result5);

        assert(result1 == 7);
        assert(result2 == 5);
        assert(result3 == 6);
        assert(result4 == 10);
        assert(result5 == 11);
    }
}

static void BM_example_input_day06_part2(benchmark::State& state)
{
    for (auto _ : state) {
        const auto result1 = day06_part2("mjqjpqmgbljsphdztnvjfqwrcgsmlb");
        const auto result2 = day06_part2("bvwbjplbgvbhsrlpgdmjqwftvncz");
        const auto result3 = day06_part2("nppdvjthqldpwncqszvftbrmjlhg");
        const auto result4 = day06_part2("nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg");
        const auto result5 = day06_part2("zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw");

        benchmark::DoNotOptimize(result1);
        benchmark::DoNotOptimize(result2);
        benchmark::DoNotOptimize(result3);
        benchmark::DoNotOptimize(result4);
        benchmark::DoNotOptimize(result5);

        assert(result1 == 19);
        assert(result2 == 23);
        assert(result3 == 23);
        assert(result4 == 29);
        assert(result5 == 26);
    }
}

static void BM_example_input_day07_part1(benchmark::State& state)
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

    for (auto _ : state) {
        const auto result = day07_part1(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 95437);
    }
}

static void BM_example_input_day07_part2(benchmark::State& state)
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

    for (auto _ : state) {
        const auto result = day07_part2(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 24933642);
    }
}

static void BM_example_input_day08_part1(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "30373",
        "25512",
        "65332",
        "33549",
        "35390",
    };

    for (auto _ : state) {
        const auto result = day08_part1(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 21);
    }
}

static void BM_example_input_day08_part2(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "30373",
        "25512",
        "65332",
        "33549",
        "35390",
    };

    for (auto _ : state) {
        const auto result = day08_part2(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 8);
    }
}

static void BM_example_input_day09_part1(benchmark::State& state)
{
    const std::vector<std::string> lines = {
        "R 4",
        "U 4",
        "L 3",
        "D 1",
        "R 4",
        "D 1",
        "L 5",
        "R 2",
    };

    for (auto _ : state) {
        const auto result = day09_part1(lines);
        benchmark::DoNotOptimize(result);
        assert(result == 13);
    }
}

static void BM_example_input_day09_part2(benchmark::State& state)
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

    for (auto _ : state) {
        const auto result1 = day09_part2(lines1);
        const auto result2 = day09_part2(lines2);

        benchmark::DoNotOptimize(result1);
        benchmark::DoNotOptimize(result2);

        assert(result1 == 1);
        assert(result2 == 36);
    }
}

static void BM_puzzle_input_day01_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day01"));
    const GroupedNumbers grouped_numbers = read_grouped_numbers(*input_stream);

    for (auto _ : state) {
        const auto result = day01_part1(grouped_numbers);
        benchmark::DoNotOptimize(result);
        assert(result == 68775);
    }
}

static void BM_puzzle_input_day01_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day01"));
    const GroupedNumbers grouped_numbers = read_grouped_numbers(*input_stream);

    for (auto _ : state) {
        const auto result = day01_part2(grouped_numbers);
        benchmark::DoNotOptimize(result);
        assert(result == 202585);
    }
}

static void BM_puzzle_input_day02_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day02"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day02_part1(input);
        benchmark::DoNotOptimize(result);
        assert(result == 13005);
    }
}

static void BM_puzzle_input_day02_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day02"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day02_part2(input);
        benchmark::DoNotOptimize(result);
        assert(result == 11373);
    }
}

static void BM_puzzle_input_day03_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day03"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day03_part1(input);
        benchmark::DoNotOptimize(result);
        assert(result == 8240);
    }
}

static void BM_puzzle_input_day03_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day03"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day03_part2(input);
        benchmark::DoNotOptimize(result);
        assert(result == 2587);
    }
}

static void BM_puzzle_input_day04_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day04"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day04_part1(input);
        benchmark::DoNotOptimize(result);
        assert(result == 471);
    }
}

static void BM_puzzle_input_day04_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day04"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day04_part2(input);
        benchmark::DoNotOptimize(result);
        assert(result == 888);
    }
}

static void BM_puzzle_input_day05_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day05"));
    const std::vector<std::string> input = read_lines_and_preserve_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day05_part1(input);
        benchmark::DoNotOptimize(result);
        assert(result == "PSNRGBTFT");
    }
}

static void BM_puzzle_input_day05_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day05"));
    const std::vector<std::string> input = read_lines_and_preserve_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day05_part2(input);
        benchmark::DoNotOptimize(result);
        assert(result == "BNTZFPMMW");
    }
}

static void BM_puzzle_input_day06_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day06"));
    const std::string line = read_single_line(*input_stream);

    for (auto _ : state) {
        const auto result = day06_part1(line);
        benchmark::DoNotOptimize(result);
        assert(result == 1210);
    }
}

static void BM_puzzle_input_day06_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day06"));
    const std::string line = read_single_line(*input_stream);

    for (auto _ : state) {
        const auto result = day06_part2(line);
        benchmark::DoNotOptimize(result);
        assert(result == 3476);
    }
}

static void BM_puzzle_input_day07_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day07"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day07_part1(input);
        benchmark::DoNotOptimize(result);
        assert(result == 1581595);
    }
}

static void BM_puzzle_input_day07_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day07"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day07_part2(input);
        benchmark::DoNotOptimize(result);
        assert(result == 1544176);
    }
}

static void BM_puzzle_input_day08_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day08"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day08_part1(input);
        benchmark::DoNotOptimize(result);
        assert(result == 1533);
    }
}

static void BM_puzzle_input_day08_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day08"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day08_part2(input);
        benchmark::DoNotOptimize(result);
        assert(result == 345744);
    }
}

static void BM_puzzle_input_day09_part1(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day09"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day09_part1(input);
        benchmark::DoNotOptimize(result);
        assert(result == 6209);
    }
}

static void BM_puzzle_input_day09_part2(benchmark::State& state)
{
    auto input_stream = open_input_file(find_input_file("day09"));
    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    for (auto _ : state) {
        const auto result = day09_part2(input);
        benchmark::DoNotOptimize(result);
        assert(result == 2460);
    }
}

BENCHMARK(BM_example_input_day01_part1);
BENCHMARK(BM_example_input_day01_part2);
BENCHMARK(BM_example_input_day02_part1);
BENCHMARK(BM_example_input_day02_part2);
BENCHMARK(BM_example_input_day03_part1);
BENCHMARK(BM_example_input_day03_part2);
BENCHMARK(BM_example_input_day04_part1);
BENCHMARK(BM_example_input_day04_part2);
BENCHMARK(BM_example_input_day05_part1);
BENCHMARK(BM_example_input_day05_part2);
BENCHMARK(BM_example_input_day06_part1);
BENCHMARK(BM_example_input_day06_part2);
BENCHMARK(BM_example_input_day07_part1);
BENCHMARK(BM_example_input_day07_part2);
BENCHMARK(BM_example_input_day08_part1);
BENCHMARK(BM_example_input_day08_part2);
BENCHMARK(BM_example_input_day09_part1);
BENCHMARK(BM_example_input_day09_part2);

BENCHMARK(BM_puzzle_input_day01_part1);
BENCHMARK(BM_puzzle_input_day01_part2);
BENCHMARK(BM_puzzle_input_day02_part1);
BENCHMARK(BM_puzzle_input_day02_part2);
BENCHMARK(BM_puzzle_input_day03_part1);
BENCHMARK(BM_puzzle_input_day03_part2);
BENCHMARK(BM_puzzle_input_day04_part1);
BENCHMARK(BM_puzzle_input_day04_part2);
BENCHMARK(BM_puzzle_input_day05_part1);
BENCHMARK(BM_puzzle_input_day05_part2);
BENCHMARK(BM_puzzle_input_day06_part1);
BENCHMARK(BM_puzzle_input_day06_part2);
BENCHMARK(BM_puzzle_input_day07_part1);
BENCHMARK(BM_puzzle_input_day07_part2);
BENCHMARK(BM_puzzle_input_day08_part1);
BENCHMARK(BM_puzzle_input_day08_part2);
BENCHMARK(BM_puzzle_input_day09_part1);
BENCHMARK(BM_puzzle_input_day09_part2);
