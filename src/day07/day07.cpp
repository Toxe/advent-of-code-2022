#include "day07.hpp"

#include <algorithm>
#include <functional>
#include <numeric>
#include <string_view>
#include <tuple>

using InputIterator = std::vector<std::string>::const_iterator;

std::tuple<int, InputIterator> scan(InputIterator input_iter, const InputIterator& input_end, const std::function<void(int)>& collect_directory_sizes)
{
    int directory_size = 0;

    ++input_iter;  // skip the first line in each directory ("$ ls")

    // sum sizes of all files in current directory, until we reach the first command
    while (input_iter != input_end && !input_iter->starts_with('$')) {
        if (!input_iter->starts_with("dir"))
            directory_size += std::stoi(*input_iter);

        ++input_iter;
    }

    // add subdirectory sizes until we need to go back to the parent directory
    while (input_iter != input_end && !input_iter->starts_with("$ cd ..")) {
        const auto [subdirectory_size, it] = scan(std::next(input_iter), input_end, collect_directory_sizes);

        directory_size += subdirectory_size;
        input_iter = it;
    }

    collect_directory_sizes(directory_size);

    return {directory_size, (input_iter != input_end) ? std::next(input_iter) : input_iter};
}

int day07_part1(const std::vector<std::string>& lines)
{
    std::vector<int> directory_sizes;

    scan(std::next(lines.begin()), lines.end(), [&](const int size) {
        if (size <= 100'000)
            directory_sizes.push_back(size);
    });

    return std::accumulate(directory_sizes.begin(), directory_sizes.end(), 0);
}

int day07_part2(const std::vector<std::string>& lines)
{
    std::vector<int> directory_sizes;

    scan(std::next(lines.begin()), lines.end(), [&](const int size) { directory_sizes.push_back(size); });

    const int needed = 30'000'000 - (70'000'000 - *std::max_element(directory_sizes.begin(), directory_sizes.end()));

    std::sort(directory_sizes.begin(), directory_sizes.end());
    return *std::upper_bound(directory_sizes.begin(), directory_sizes.end(), needed);
}
