#include "print_results.hpp"
#include "read_grid.hpp"
#include "read_input.hpp"

#include "day08.hpp"

int main(int argc, const char* argv[])
{
    auto input_stream = open_input_file(get_input_filename({argv, static_cast<std::size_t>(argc)}));

    if (!input_stream)
        return 1;

    auto grid = read_digit_grid(*input_stream);

    print_result(8, 1, day08_part1(grid));
    print_result(8, 2, day08_part2(grid));
}
