#include <iostream>

#include "read_input.hpp"

#include "dayDAYXX.hpp"

int main(int argc, const char* argv[])
{
    auto input_stream = open_input_file(get_input_filename({argv, static_cast<std::size_t>(argc)}));

    if (!input_stream)
        return 1;

    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    std::cout << "day DAYXX, part 1: " << dayDAYXX_part1(input) << '\n';
    std::cout << "day DAYXX, part 2: " << dayDAYXX_part2(input) << '\n';
}
