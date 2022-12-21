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

int calc_scenic_score(ByteGrid::RowAndColIterator& row_or_col_iter, const int col_or_row_index, const int direction)
{
    const auto begin_of_row_or_col = row_or_col_iter.begin();
    const auto end_of_row_or_col = row_or_col_iter.end();
    const auto current_tree_pos = begin_of_row_or_col + col_or_row_index;
    const auto start_pos = current_tree_pos + direction;
    const auto end = direction > 0 ? end_of_row_or_col : begin_of_row_or_col - 1;

    for (auto it = start_pos; it != end; it += direction)
        if (*it >= *current_tree_pos)
            return static_cast<int>((start_pos - it) + 1);

    return direction > 0 ? static_cast<int>(end_of_row_or_col - start_pos) : col_or_row_index;
}

int scenic_score(ByteGrid& grid, const int col, const int row)
{
    auto search_row = grid.row(row);
    auto search_col = grid.col(col);

    const auto r = calc_scenic_score(search_row, col, direction_forward);
    const auto l = calc_scenic_score(search_row, col, direction_backward);
    const auto u = calc_scenic_score(search_col, row, direction_forward);
    const auto d = calc_scenic_score(search_col, row, direction_backward);

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
