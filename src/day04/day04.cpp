#include "day04.hpp"

#include <algorithm>
#include <functional>
#include <regex>
#include <stdexcept>
#include <utility>

using Pair = std::pair<int, int>;
using CompareStrategy = std::function<bool(Pair, Pair)>;

std::tuple<Pair, Pair> parse_pairs(const std::string& line)
{
    static const std::regex re{R"((\d+)-(\d+),(\d+)-(\d+))"};

    std::smatch m;

    if (!std::regex_match(line, m, re) || m.size() != 5)
        throw std::runtime_error{"invalid input"};

    return {{std::stoi(m[1]), std::stoi(m[2])}, {std::stoi(m[3]), std::stoi(m[4])}};
}

int count_pairs(const std::vector<std::string>& lines, const CompareStrategy& strategy)
{
    return static_cast<int>(std::count_if(lines.begin(), lines.end(),
        [&](const auto& line) {
            const auto [pair1, pair2] = parse_pairs(line);
            return strategy(pair1, pair2) || strategy(pair2, pair1);
        }));
}

int day04_part1(const std::vector<std::string>& lines)
{
    return count_pairs(lines, [](Pair pair1, Pair pair2) { return pair2.first >= pair1.first && pair2.second <= pair1.second; });
}

int day04_part2(const std::vector<std::string>& lines)
{
    return count_pairs(lines, [](Pair pair1, Pair pair2) { return pair2.first >= pair1.first && pair2.first <= pair1.second; });
}
