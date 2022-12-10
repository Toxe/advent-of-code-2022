#include <iostream>

#include "read_grouped_numbers.hpp"
#include "read_input.hpp"

#include "day01.hpp"

int main(int argc, const char* argv[])
{
    auto input_stream = open_input_file(get_input_filename({argv, static_cast<std::size_t>(argc)}));

    if (!input_stream)
        return 1;

    const GroupedNumbers grouped_numbers = read_grouped_numbers(*input_stream);

    std::cout << "day 01, part 1: " << day01_part1(grouped_numbers) << '\n';
    std::cout << "day 01, part 2: " << day01_part2(grouped_numbers) << '\n';
}
