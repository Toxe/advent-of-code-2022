#include "day08.hpp"

#include <algorithm>
#include <numeric>
#include <vector>

constexpr int direction_forward = 1;
constexpr int direction_backward = -1;

char tree_height(const std::vector<std::string>& lines, const int row, const int col)
{
    return static_cast<char>(lines[static_cast<std::size_t>(row)][static_cast<std::size_t>(col)] - '0');
}

void mark_highest_trees_in_row(const std::vector<std::string>& lines, std::vector<std::vector<char>>& marked_trees, const int row, const int direction)
{
    const int num_cols = static_cast<int>(lines[0].size());
    const int start = direction > 0 ? 0 : num_cols - 1;
    const int end = direction > 0 ? num_cols : -1;

    char highest_tree = -1;

    for (int col = start; col != end; col += direction) {
        const char tree = tree_height(lines, row, col);

        if (tree > highest_tree) {
            highest_tree = tree;
            marked_trees[static_cast<std::size_t>(row)][static_cast<std::size_t>(col)] = tree;
        }

        if (tree == 9)
            break;
    }
}

void mark_highest_trees_in_column(const std::vector<std::string>& lines, std::vector<std::vector<char>>& marked_trees, const int col, const int direction)
{
    const int num_rows = static_cast<int>(lines.size());
    const int start = direction > 0 ? 0 : num_rows - 1;
    const int end = direction > 0 ? num_rows : -1;

    char highest_tree = -1;

    for (int row = start; row != end; row += direction) {
        const char tree = tree_height(lines, row, col);

        if (tree > highest_tree) {
            highest_tree = tree;
            marked_trees[static_cast<std::size_t>(row)][static_cast<std::size_t>(col)] = tree;
        }

        if (tree == 9)
            break;
    }
}

int calc_scenic_score_horizontally(const std::vector<std::string>& lines, const int row, const int col, const int direction)
{
    const int num_cols = static_cast<int>(lines[0].size());
    const int start = col + direction;
    const int end = direction > 0 ? num_cols : -1;
    const char current_tree_height = tree_height(lines, row, col);

    for (int pos = start; pos != end; pos += direction)
        if (tree_height(lines, row, pos) >= current_tree_height)
            return direction > 0 ? pos - col : col - pos;

    return direction > 0 ? num_cols - col - 1 : col;
}

int calc_scenic_score_vertically(const std::vector<std::string>& lines, const int row, const int col, const int direction)
{
    const int num_rows = static_cast<int>(lines.size());
    const int start = row + direction;
    const int end = direction > 0 ? num_rows : -1;
    const char current_tree_height = tree_height(lines, row, col);

    for (int pos = start; pos != end; pos += direction)
        if (tree_height(lines, pos, col) >= current_tree_height)
            return direction > 0 ? pos - row : row - pos;

    return direction > 0 ? num_rows - row - 1 : row;
}

int scenic_score(const std::vector<std::string>& lines, const int row, const int col)
{
    const auto r = calc_scenic_score_horizontally(lines, row, col, direction_forward);
    const auto l = calc_scenic_score_horizontally(lines, row, col, direction_backward);
    const auto u = calc_scenic_score_vertically(lines, row, col, direction_forward);
    const auto d = calc_scenic_score_vertically(lines, row, col, direction_backward);

    return r * l * u * d;
}

int day08_part1(const std::vector<std::string>& lines)
{
    std::vector<std::vector<char>> marked_trees;

    for (int row = 0; row < std::ssize(lines); ++row)
        marked_trees.emplace_back(lines[0].size(), static_cast<char>(-1));

    for (int row = 0; row < std::ssize(lines); ++row) {
        mark_highest_trees_in_row(lines, marked_trees, row, direction_forward);
        mark_highest_trees_in_row(lines, marked_trees, row, direction_backward);
    }

    for (int col = 0; col < std::ssize(lines[0]); ++col) {
        mark_highest_trees_in_column(lines, marked_trees, col, direction_forward);
        mark_highest_trees_in_column(lines, marked_trees, col, direction_backward);
    }

    return std::accumulate(marked_trees.begin(), marked_trees.end(), 0, [](auto current_sum, auto row) {
        return current_sum + static_cast<int>(std::count_if(row.begin(), row.end(), [](auto c) {
            return c >= 0;
        }));
    });
}

int day08_part2(const std::vector<std::string>& lines)
{
    int max_score = 0;

    for (int row = 1; row < std::ssize(lines) - 1; ++row)
        for (int col = 1; col < std::ssize(lines[0]) - 1; ++col)
            max_score = std::max(max_score, scenic_score(lines, row, col));

    return max_score;
}
