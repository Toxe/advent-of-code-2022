#pragma once

#include <cassert>
#include <vector>

template <typename T>
class Grid {
public:
    using value_type = T;

    Grid(int rows, int cols);
    Grid(int rows, int cols, const T& value);

    [[nodiscard]] int rows() const { return rows_; }
    [[nodiscard]] int cols() const { return cols_; }

    [[nodiscard]] T& value(int row, int col);
    [[nodiscard]] const T& value(int row, int col) const;

private:
    std::vector<T> data_;

    int rows_;
    int cols_;

    [[nodiscard]] std::size_t idx(int row, int col) const;
};

template <typename T>
Grid<T>::Grid(const int rows, const int cols) : data_(static_cast<std::size_t>(rows * cols)), rows_{rows}, cols_{cols} { }

template <typename T>
Grid<T>::Grid(const int rows, const int cols, const T& value) : data_(static_cast<std::size_t>(rows * cols), value), rows_{rows}, cols_{cols} { }

template <typename T>
T& Grid<T>::value(int row, int col)
{
    assert(row >= 0 && col >= 0);
    assert(idx(row, col) < data_.size());

    return data_[idx(row, col)];
}

template <typename T>
const T& Grid<T>::value(int row, int col) const
{
    assert(idx(row, col) >= 0 && idx(row, col) < data_.size());

    return data_[idx(row, col)];
}

template <typename T>
std::size_t Grid<T>::idx(const int row, const int col) const
{
    assert(row >= 0 && col >= 0);

    return static_cast<std::size_t>(row * cols_) + static_cast<std::size_t>(col);
}

using ByteGrid = Grid<uint8_t>;
