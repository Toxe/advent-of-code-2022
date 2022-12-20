#include "day08.hpp"

#include <algorithm>
#include <numeric>

constexpr int direction_forward = 1;
constexpr int direction_backward = -1;

void mark_highest_trees(ByteGrid::RowAndColIterator& row_or_col_iter, Grid<char>::RowAndColIterator& marked_trees_iter, const int direction)
{
    const auto begin = direction > 0 ? row_or_col_iter.begin() : row_or_col_iter.end() - 1;
    const auto end = direction > 0 ? row_or_col_iter.end() : row_or_col_iter.begin() - 1;

    auto current_marked_tree = direction > 0 ? marked_trees_iter.begin() : marked_trees_iter.end() - 1;
    char highest_tree = -1;

    for (auto it = begin; it != end; it += direction) {
        const auto tree = static_cast<char>(*it);

        if (tree > highest_tree) {
            highest_tree = tree;
            *current_marked_tree = tree;
        }

        if (tree == 9)
            break;

        current_marked_tree += direction;
    }
}

int calc_scenic_score_horizontally(const ByteGrid& grid, const int grid_col, const int grid_row, const int direction)
{
    const int start = grid_col + direction;
    const int end = direction > 0 ? grid.width() : -1;
    const auto current_tree_height = grid.value(grid_col, grid_row);

    for (int pos = start; pos != end; pos += direction)
        if (grid.value(pos, grid_row) >= current_tree_height)
            return direction > 0 ? pos - grid_col : grid_col - pos;

    return direction > 0 ? grid.width() - grid_col - 1 : grid_col;
}

int calc_scenic_score_vertically(const ByteGrid& grid, const int grid_col, const int grid_row, const int direction)
{
    const int start = grid_row + direction;
    const int end = direction > 0 ? grid.height() : -1;
    const auto current_tree_height = grid.value(grid_col, grid_row);

    for (int pos = start; pos != end; pos += direction)
        if (grid.value(grid_col, pos) >= current_tree_height)
            return direction > 0 ? pos - grid_row : grid_row - pos;

    return direction > 0 ? grid.height() - grid_row - 1 : grid_row;
}

int scenic_score(ByteGrid& grid, const int col, const int row)
{
    const auto r = calc_scenic_score_horizontally(grid, col, row, direction_forward);
    const auto l = calc_scenic_score_horizontally(grid, col, row, direction_backward);
    const auto u = calc_scenic_score_vertically(grid, col, row, direction_forward);
    const auto d = calc_scenic_score_vertically(grid, col, row, direction_backward);

    return r * l * u * d;
}

int day08_part1(ByteGrid& grid)
{
    Grid<char> marked_trees{grid.width(), grid.height(), -1};

    auto marked_trees_row = marked_trees.rows().begin();

    for (auto row : grid.rows()) {
        mark_highest_trees(row, marked_trees_row, direction_forward);
        mark_highest_trees(row, marked_trees_row, direction_backward);
        ++marked_trees_row;
    }

    auto marked_trees_col = marked_trees.cols().begin();

    for (auto col : grid.cols()) {
        mark_highest_trees(col, marked_trees_col, direction_forward);
        mark_highest_trees(col, marked_trees_col, direction_backward);
        ++marked_trees_col;
    }

    return static_cast<int>(std::count_if(marked_trees.cbegin(), marked_trees.cend(), [](auto tree) { return tree >= 0; }));
}

int day08_part2(ByteGrid& grid)
{
    int max_score = 0;

    for (int row = 1; row < grid.height() - 1; ++row)
        for (int col = 1; col < grid.width() - 1; ++col)
            max_score = std::max(max_score, scenic_score(grid, col, row));

    return max_score;
}
