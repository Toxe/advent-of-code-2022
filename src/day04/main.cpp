#include <iostream>

#include "read_input.hpp"

#include "day04.hpp"

int main(int argc, const char* argv[])
{
    auto input_file = open_input_file({argv, static_cast<std::size_t>(argc)});

    if (!input_file)
        return 1;

    const std::vector<std::string> input = read_lines(*input_file);

    std::cout << "day 04, part 1: " << day04_part1(input) << '\n';
    std::cout << "day 04, part 2: " << day04_part2(input) << '\n';
}