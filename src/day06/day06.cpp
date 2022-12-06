#include "day06.hpp"

#include <algorithm>

int find_marker(const std::string& line, const int marker_length)
{
    for (auto it = line.begin(); it != std::prev(line.end(), marker_length - 1); ++it) {
        std::string s{it, it + marker_length};
        std::sort(s.begin(), s.end());

        if (std::adjacent_find(s.begin(), s.end()) == s.end())
            return static_cast<int>(std::distance(line.begin(), it) + marker_length);
    }

    return -1;
}

int day06_part1(const std::string& line)
{
    return find_marker(line, 4);
}

int day06_part2(const std::string& line)
{
    return find_marker(line, 14);
}
