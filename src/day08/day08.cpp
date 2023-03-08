#include "day08.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>

template <typename ValueIter, typename MarkedTreeIter>
void mark_highest_trees(ValueIter begin, ValueIter end, MarkedTreeIter marked_trees_iter)
{
    char highest_tree = -1;

    for (auto it = begin; it != end; ++it) {
        const auto tree = static_cast<char>(*it);

        if (tree > highest_tree) {
            highest_tree = tree;
            *marked_trees_iter = tree;
        }

        if (tree == 9)
            break;

        ++marked_trees_iter;
    }
}

template <typename ValueIter>
int calc_scenic_score(ValueIter begin, ValueIter end)
{
    const auto current_tree = *begin;

    if (const auto it = std::find_if(begin + 1, end, [&](auto tree) { return tree >= current_tree; }); it != end)
        return static_cast<int>(it - begin);

    return static_cast<int>(end - begin - 1);
}

int scenic_score(const ByteGrid& grid, const int col, const int row)
{
    const auto search_row = grid.row(row);
    const auto search_col = grid.col(col);

    const auto r = calc_scenic_score(search_row.begin() + col, search_row.end());
    const auto l = calc_scenic_score(search_row.rbegin() + (grid.width() - col - 1), search_row.rend());
    const auto d = calc_scenic_score(search_col.begin() + row, search_col.end());
    const auto u = calc_scenic_score(search_col.rbegin() + (grid.height() - row - 1), search_col.rend());

    return r * l * d * u;
}

template <typename GridRowsOrCols, typename MarkedTreesRowsOrCols>
void mark_trees_in_row_or_col(GridRowsOrCols rows_or_cols, MarkedTreesRowsOrCols marked_trees_rows_or_cols)
{
    auto marked_trees_rows_or_cols_iter = marked_trees_rows_or_cols.begin();

    for (auto row_or_col : rows_or_cols) {
        mark_highest_trees(row_or_col.begin(), row_or_col.end(), marked_trees_rows_or_cols_iter->begin());
        mark_highest_trees(row_or_col.rbegin(), row_or_col.rend(), marked_trees_rows_or_cols_iter->rbegin());
        ++marked_trees_rows_or_cols_iter;
    }
}

int day08_part1(const ByteGrid& grid)
{
    Grid<char> marked_trees{grid.width(), grid.height(), -1};

    mark_trees_in_row_or_col(grid.rows(), marked_trees.rows());
    mark_trees_in_row_or_col(grid.cols(), marked_trees.cols());

    return static_cast<int>(std::count_if(marked_trees.cbegin(), marked_trees.cend(), [](auto tree) { return tree >= 0; }));
}

int day08_part2(const ByteGrid& grid)
{
    int max_score = 0;

    for (int row = 1; row < grid.height() - 1; ++row)
        for (int col = 1; col < grid.width() - 1; ++col)
            max_score = std::max(max_score, scenic_score(grid, col, row));

    return max_score;
}
