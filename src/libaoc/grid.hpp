#pragma once

#include <cassert>
#include <vector>

#include "coords.hpp"

template <typename T>
class GridCell;

template <typename T>
class Grid {
public:
    using value_type = T;

    Grid(int cols, int rows);
    Grid(int cols, int rows, const T& value);

    [[nodiscard]] int cols() const { return cols_; }
    [[nodiscard]] int rows() const { return rows_; }

    [[nodiscard]] T& value(int col, int row);
    [[nodiscard]] const T& value(int col, int row) const;

    [[nodiscard]] T& value(const Coords& coords);
    [[nodiscard]] const T& value(const Coords& coords) const;

    [[nodiscard]] GridCell<T> cell(int col, int row);
    [[nodiscard]] GridCell<T> cell(const Coords& coords);

private:
    std::vector<T> data_;

    int cols_;
    int rows_;

    [[nodiscard]] std::size_t idx(int col, int row) const;
    [[nodiscard]] std::size_t idx(const Coords& coords) const;
};

template <typename T>
Grid<T>::Grid(const int cols, const int rows) : data_(static_cast<std::size_t>(rows * cols)), cols_{cols}, rows_{rows} { }

template <typename T>
Grid<T>::Grid(const int cols, const int rows, const T& value) : data_(static_cast<std::size_t>(rows * cols), value), cols_{cols}, rows_{rows} { }

template <typename T>
T& Grid<T>::value(const int col, const int row)
{
    assert(col >= 0 && row >= 0);
    assert(idx(col, row) < data_.size());

    return data_[idx(col, row)];
}

template <typename T>
const T& Grid<T>::value(const int col, const int row) const
{
    assert(col >= 0 && row >= 0);
    assert(idx(col, row) < data_.size());

    return data_[idx(col, row)];
}

template <typename T>
T& Grid<T>::value(const Coords& coords)
{
    assert(coords.x >= 0 && coords.y >= 0);
    assert(idx(coords) < data_.size());

    return data_[idx(coords)];
}

template <typename T>
const T& Grid<T>::value(const Coords& coords) const
{
    assert(coords.x >= 0 && coords.y >= 0);
    assert(idx(coords) < data_.size());

    return data_[idx(coords)];
}

template <typename T>
GridCell<T> Grid<T>::cell(const int col, const int row)
{
    return GridCell<T>{this, Coords{col, row}};
}

template <typename T>
GridCell<T> Grid<T>::cell(const Coords& coords)
{
    return GridCell<T>{this, coords};
}

template <typename T>
std::size_t Grid<T>::idx(const int col, const int row) const
{
    assert(row >= 0 && col >= 0);

    return static_cast<std::size_t>(row * cols_) + static_cast<std::size_t>(col);
}

template <typename T>
std::size_t Grid<T>::idx(const Coords& coords) const
{
    assert(coords.x >= 0 && coords.y >= 0);

    return static_cast<std::size_t>(coords.y * cols_) + static_cast<std::size_t>(coords.x);
}

using ByteGrid = Grid<uint8_t>;
