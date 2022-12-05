#include <iostream>

#include "read_input.hpp"

#include "dayDAYXX.hpp"

int main(int argc, const char* argv[])
{
    auto input_file = open_input_file({argv, static_cast<std::size_t>(argc)});

    if (!input_file)
        return 1;

    const std::vector<std::string> input = read_lines(*input_file);

    std::cout << "day DAYXX, part 1: " << dayDAYXX_part1(input) << '\n';
    std::cout << "day DAYXX, part 2: " << dayDAYXX_part2(input) << '\n';
}
