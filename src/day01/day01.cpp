#include "day01.hpp"

#include <algorithm>
#include <functional>
#include <numeric>

int day01_part1(const GroupedNumbers& grouped_numbers)
{
    int max = 0;

    for (const auto& group : grouped_numbers)
        max = std::max(max, std::accumulate(group.begin(), group.end(), 0));

    return max;
}

int day01_part2(const GroupedNumbers& grouped_numbers)
{
    std::vector<int> sums(grouped_numbers.size());

    std::transform(grouped_numbers.begin(), grouped_numbers.end(), sums.begin(),
        [](const auto& group) { return std::accumulate(group.begin(), group.end(), 0); });

    std::partial_sort(sums.begin(), sums.begin() + 3, sums.end(), std::greater{});

    return std::accumulate(sums.begin(), sums.begin() + 3, 0);
}
