#include <iostream>

#include "read_input.hpp"
#include "read_grid.hpp"

#include "day08.hpp"

int main(int argc, const char* argv[])
{
    auto input_stream = open_input_file(get_input_filename({argv, static_cast<std::size_t>(argc)}));

    if (!input_stream)
        return 1;

    const auto grid = read_digit_grid(*input_stream);

    std::cout << "day 08, part 1: " << day08_part1(grid) << '\n';
    std::cout << "day 08, part 2: " << day08_part2(grid) << '\n';
}
