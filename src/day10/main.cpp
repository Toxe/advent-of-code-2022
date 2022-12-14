#include "print_results.hpp"
#include "read_input.hpp"

#include "day10.hpp"

int main(int argc, const char* argv[])
{
    auto input_stream = open_input_file(get_input_filename({argv, static_cast<std::size_t>(argc)}));

    if (!input_stream)
        return 1;

    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    print_result(10, 1, day10_part1(input));
    print_result(10, 2, day10_part2(input));
}
