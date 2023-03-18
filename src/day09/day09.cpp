#include "day09.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "coords.hpp"

using Coords16 = Coords<short>;

struct Rope {
    explicit Rope(const int num_knots) : knots(static_cast<std::size_t>(num_knots)) { }
    std::vector<Coords16> knots;
};

struct Motion {
    Coords16 delta;
    int steps = 0;
};

Motion parse_motions(const std::string& line)
{
    const int steps = std::stoi(line.substr(2));

    switch (line[0]) {
        case 'U': return Motion{{0, -1}, steps};
        case 'D': return Motion{{0, +1}, steps};
        case 'L': return Motion{{-1, 0}, steps};
        case 'R': return Motion{{+1, 0}, steps};
        default:
            throw std::runtime_error{"invalid input"};
    }
}

void perform_follow_motion(const Coords16& head, Coords16& knot)
{
    const Coords16 delta = head - knot;
    // {static_cast<Coords16::coordinates_type>(head.x - knot.x), static_cast<Coords16::coordinates_type>(head.y - knot.y)};
    const Coords16 dist{static_cast<Coords16::coordinates_type>(std::abs(delta.x)), static_cast<Coords16::coordinates_type>(std::abs(delta.y))};

    if (dist.x != 2 && dist.y != 2)
        return;

    knot.move(
        (dist.x == 2) ? delta.x / 2 : delta.x,
        (dist.y == 2) ? delta.y / 2 : delta.y);
}

void perform_motions(Motion motion, Rope& rope, std::vector<Coords16>& tail_positions)
{
    while (motion.steps-- > 0) {
        rope.knots[0] += motion.delta;

        for (int i = 1; i < std::ssize(rope.knots); ++i)
            perform_follow_motion(rope.knots[static_cast<std::size_t>(i - 1)], rope.knots[static_cast<std::size_t>(i)]);

        tail_positions.push_back(rope.knots.back());
    }
}

int calc_number_of_tail_positions(std::vector<Coords16>& tail_positions)
{
    std::sort(tail_positions.begin(), tail_positions.end());
    const auto it = std::unique(tail_positions.begin(), tail_positions.end(), [](auto& a, auto& b) { return a == b; });
    return static_cast<int>(std::distance(tail_positions.begin(), it));
}

int do_it(const std::vector<std::string>& lines, const int num_knots)
{
    Rope rope{num_knots};
    std::vector<Coords16> tail_positions;

    for (const auto& line : lines)
        perform_motions(parse_motions(line), rope, tail_positions);

    return calc_number_of_tail_positions(tail_positions);
}

int day09_part1(const std::vector<std::string>& lines)
{
    return do_it(lines, 2);
}

int day09_part2(const std::vector<std::string>& lines)
{
    return do_it(lines, 10);
}
