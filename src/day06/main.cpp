#include <iostream>

#include "read_input.hpp"

#include "day06.hpp"

int main(int argc, const char* argv[])
{
    auto input_file = open_input_file({argv, static_cast<std::size_t>(argc)});

    if (!input_file)
        return 1;

    const std::string line = read_single_line(*input_file);

    std::cout << "day 06, part 1: " << day06_part1(line) << '\n';
    std::cout << "day 06, part 2: " << day06_part2(line) << '\n';
}
