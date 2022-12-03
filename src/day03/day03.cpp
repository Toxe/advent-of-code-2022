#include "day03.hpp"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <string_view>

int priority(const char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    else
        return c - 'A' + 1 + 26;
}

int day03_part1(const std::vector<std::string>& lines)
{
    return std::accumulate(lines.begin(), lines.end(), 0,
        [](int current_sum, const auto& line) {
            return current_sum + priority(*std::find_first_of(line.begin(), line.begin() + std::ssize(line) / 2, line.begin() + std::ssize(line) / 2, line.end()));
        });
}

int day03_part2(const std::vector<std::string>& lines)
{
    assert(lines.size() % 3 == 0);

    int sum = 0;

    for (auto it = lines.cbegin(); it != lines.cend(); std::advance(it, 3)) {
        const std::string_view line1{*it};
        std::string line2{*(it + 1)};
        std::string line3{*(it + 2)};

        std::sort(line2.begin(), line2.end());
        std::sort(line3.begin(), line3.end());

        // find a character that all three lines contain
        const auto pos = std::find_if(line1.begin(), line1.end(),
            [&](const char c) {
                return std::binary_search(line2.begin(), line2.end(), c) && std::binary_search(line3.begin(), line3.end(), c);
            });

        sum += priority(*pos);
    }

    return sum;
}
