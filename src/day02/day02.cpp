#include "day02.hpp"

#include <cassert>
#include <numeric>
#include <stdexcept>

enum class RPS {
    Rock = 1,
    Paper,
    Scissors
};

enum class Result {
    Loss = 0,
    Draw = 3,
    Win = 6
};

int to_int(const RPS hand) { return static_cast<int>(hand); }
int to_int(const Result result) { return static_cast<int>(result); }

RPS get_hand(const char base, const char c)
{
    return static_cast<RPS>(c - base + 1);
}

Result get_result(const char c)
{
    switch (c) {
        case 'X': return Result::Loss;
        case 'Y': return Result::Draw;
        case 'Z': return Result::Win;
        default:
            throw std::runtime_error{"invalid input"};
    }
}

Result compare_hands(const RPS player1, const RPS player2)
{
    if (player1 == player2)
        return Result::Draw;

    switch (player1) {
        case RPS::Rock: return player2 == RPS::Paper ? Result::Win : Result::Loss;
        case RPS::Paper: return player2 == RPS::Scissors ? Result::Win : Result::Loss;
        case RPS::Scissors: return player2 == RPS::Rock ? Result::Win : Result::Loss;
        default:
            throw std::runtime_error{"invalid input"};
    }
}

RPS pick_hand(const RPS opponent_hand, const Result result)
{
    if (result == Result::Draw)
        return opponent_hand;

    switch (opponent_hand) {
        case RPS::Rock: return result == Result::Win ? RPS::Paper : RPS::Scissors;
        case RPS::Paper: return result == Result::Win ? RPS::Scissors : RPS::Rock;
        case RPS::Scissors: return result == Result::Win ? RPS::Rock : RPS::Paper;
        default:
            throw std::runtime_error{"invalid input"};
    }
}

int day02_part1(const std::vector<std::string>& lines)
{
    return std::accumulate(lines.begin(), lines.end(), 0,
        [](int current_sum, const auto& line) {
            assert(line.size() == 3);
            assert(line[0] >= 'A' && line[0] <= 'C');
            assert(line[2] >= 'X' && line[2] <= 'Z');

            const RPS player1 = get_hand('A', line[0]);
            const RPS player2 = get_hand('X', line[2]);

            return current_sum + to_int(compare_hands(player1, player2)) + to_int(player2);
        });
}

int day02_part2(const std::vector<std::string>& lines)
{
    return std::accumulate(lines.begin(), lines.end(), 0,
        [](int current_sum, const auto& line) {
            assert(line.size() == 3);
            assert(line[0] >= 'A' && line[0] <= 'C');
            assert(line[2] >= 'X' && line[2] <= 'Z');

            const RPS player1 = get_hand('A', line[0]);
            const Result result = get_result(line[2]);
            const RPS player2 = pick_hand(player1, result);

            return current_sum + to_int(result) + to_int(player2);
        });
}
