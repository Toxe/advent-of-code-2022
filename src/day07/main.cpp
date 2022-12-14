#include "print_results.hpp"
#include "read_input.hpp"

#include "day07.hpp"

int main(int argc, const char* argv[])
{
    auto input_stream = open_input_file(get_input_filename({argv, static_cast<std::size_t>(argc)}));

    if (!input_stream)
        return 1;

    const std::vector<std::string> input = read_lines_and_remove_empty_lines(*input_stream);

    print_result(7, 1, day07_part1(input));
    print_result(7, 2, day07_part2(input));
}
