#include "print_results.hpp"
#include "read_input.hpp"

#include "day06.hpp"

int main(int argc, const char* argv[])
{
    auto input_stream = open_input_file(get_input_filename({argv, static_cast<std::size_t>(argc)}));

    if (!input_stream)
        return 1;

    const std::string line = read_single_line(*input_stream);

    print_result(6, 1, day06_part1(line));
    print_result(6, 2, day06_part2(line));
}
