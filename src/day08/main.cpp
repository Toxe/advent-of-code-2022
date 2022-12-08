#include <iostream>

#include "read_input.hpp"

#include "day08.hpp"

int main(int argc, const char* argv[])
{
    auto input_file = open_input_file({argv, static_cast<std::size_t>(argc)});

    if (!input_file)
        return 1;

    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_file);

    std::cout << "day 08, part 1: " << day08_part1(input) << '\n';
    std::cout << "day 08, part 2: " << day08_part2(input) << '\n';
}