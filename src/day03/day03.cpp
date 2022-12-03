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
        const std::string_view line2{*(it + 1)};
        const std::string_view line3{*(it + 2)};

        // find a character that all three lines contain
        const auto pos = std::find_if(line1.begin(), line1.end(),
            [&](const char c) {
                return line2.find(c) != std::string_view::npos && line3.find(c) != std::string_view::npos;
            });

        sum += priority(*pos);
    }

    return sum;
}
