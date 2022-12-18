#include "day08.hpp"

#include <numeric>

constexpr int direction_forward = 1;
constexpr int direction_backward = -1;

void mark_highest_trees_in_row(const ByteGrid& grid, Grid<char>& marked_trees, const int row, const int direction)
{
    const int start = direction > 0 ? 0 : grid.cols() - 1;
    const int end = direction > 0 ? grid.cols() : -1;

    char highest_tree = -1;

    for (int col = start; col != end; col += direction) {
        const auto tree = static_cast<char>(grid.value(col, row));

        if (tree > highest_tree) {
            highest_tree = tree;
            marked_trees.value(col, row) = tree;
        }

        if (tree == 9)
            break;
    }
}

void mark_highest_trees_in_column(const ByteGrid& grid, Grid<char>& marked_trees, const int col, const int direction)
{
    const int start = direction > 0 ? 0 : grid.rows() - 1;
    const int end = direction > 0 ? grid.rows() : -1;

    char highest_tree = -1;

    for (int row = start; row != end; row += direction) {
        const auto tree = static_cast<char>(grid.value(col, row));

        if (tree > highest_tree) {
            highest_tree = tree;
            marked_trees.value(col, row) = tree;
        }

        if (tree == 9)
            break;
    }
}

int calc_scenic_score_horizontally(const ByteGrid& grid, const int col, const int row, const int direction)
{
    const int start = col + direction;
    const int end = direction > 0 ? grid.cols() : -1;
    const auto current_tree_height = grid.value(col, row);

    for (int pos = start; pos != end; pos += direction)
        if (grid.value(pos, row) >= current_tree_height)
            return direction > 0 ? pos - col : col - pos;

    return direction > 0 ? grid.cols() - col - 1 : col;
}

int calc_scenic_score_vertically(const ByteGrid& grid, const int col, const int row, const int direction)
{
    const int start = row + direction;
    const int end = direction > 0 ? grid.rows() : -1;
    const auto current_tree_height = grid.value(col, row);

    for (int pos = start; pos != end; pos += direction)
        if (grid.value(col, pos) >= current_tree_height)
            return direction > 0 ? pos - row : row - pos;

    return direction > 0 ? grid.rows() - row - 1 : row;
}

int scenic_score(const ByteGrid& grid, const int col, const int row)
{
    const auto r = calc_scenic_score_horizontally(grid, col, row, direction_forward);
    const auto l = calc_scenic_score_horizontally(grid, col, row, direction_backward);
    const auto u = calc_scenic_score_vertically(grid, col, row, direction_forward);
    const auto d = calc_scenic_score_vertically(grid, col, row, direction_backward);

    return r * l * u * d;
}

int day08_part1(const ByteGrid& grid)
{
    Grid<char> marked_trees{grid.cols(), grid.rows(), -1};

    for (int row = 0; row < grid.rows(); ++row) {
        mark_highest_trees_in_row(grid, marked_trees, row, direction_forward);
        mark_highest_trees_in_row(grid, marked_trees, row, direction_backward);
    }

    for (int col = 0; col < grid.cols(); ++col) {
        mark_highest_trees_in_column(grid, marked_trees, col, direction_forward);
        mark_highest_trees_in_column(grid, marked_trees, col, direction_backward);
    }

    int num = 0;

    for (int row = 0; row < marked_trees.rows(); ++row)
        for (int col = 0; col < marked_trees.cols(); ++col)
            if (marked_trees.value(col, row) >= 0)
                ++num;

    return num;
}

int day08_part2(const ByteGrid& grid)
{
    int max_score = 0;

    for (int row = 1; row < grid.rows() - 1; ++row)
        for (int col = 1; col < grid.cols() - 1; ++col)
            max_score = std::max(max_score, scenic_score(grid, col, row));

    return max_score;
}
