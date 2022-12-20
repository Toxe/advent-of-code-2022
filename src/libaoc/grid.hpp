#pragma once

#include <cassert>
#include <cstddef>
#include <iterator>
#include <vector>

#include "coords.hpp"

template <typename T>
class GridCell;

template <typename T>
class Grid {
public:
    class ValueIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        ValueIterator(pointer ptr, const difference_type stride) : ptr_{ptr}, stride_{stride} { }

        constexpr ValueIterator& operator++()
        {
            ptr_ += stride_;
            return *this;
        }

        ValueIterator operator++(int)
        {
            const ValueIterator tmp = *this;
            ptr_ += stride_;
            return tmp;
        }

        ValueIterator& operator--()
        {
            ptr_ -= stride_;
            return *this;
        }

        ValueIterator operator--(int)
        {
            const ValueIterator tmp = *this;
            ptr_ -= stride_;
            return tmp;
        }

        ValueIterator& operator+=(const difference_type n)
        {
            ptr_ += (n * stride_);
            return *this;
        }

        ValueIterator& operator-=(const difference_type n)
        {
            ptr_ -= (n * stride_);
            return *this;
        }

        reference operator*() const { return *ptr_; }

        ValueIterator operator+(const difference_type n) const { return ValueIterator{ptr_ + n * stride_, stride_}; }
        ValueIterator operator-(const difference_type n) const { return ValueIterator{ptr_ - n * stride_, stride_}; }

        friend bool operator==(const ValueIterator& a, const ValueIterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!=(const ValueIterator& a, const ValueIterator& b) { return a.ptr_ != b.ptr_; };

    private:
        pointer ptr_;
        difference_type stride_;
    };

    class RowAndColIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        RowAndColIterator(
            pointer begin,
            difference_type iter_stride,
            difference_type value_iter_stride,
            difference_type value_iter_end_diff)
            : ptr_{begin},
              iter_stride_{iter_stride},
              value_iter_stride_{value_iter_stride},
              value_iter_end_dist_{value_iter_end_diff}
        {
        }

        RowAndColIterator& operator++()
        {
            ptr_ += iter_stride_;
            return *this;
        }

        RowAndColIterator operator++(int)
        {
            RowAndColIterator tmp = *this;
            ptr_ += iter_stride_;
            return tmp;
        }

        RowAndColIterator& operator--()
        {
            ptr_ -= iter_stride_;
            return *this;
        }

        RowAndColIterator operator--(int)
        {
            RowAndColIterator tmp = *this;
            ptr_ -= iter_stride_;
            return tmp;
        }

        RowAndColIterator& operator+=(const difference_type n)
        {
            ptr_ += n * iter_stride_;
            return *this;
        }

        RowAndColIterator& operator-=(const difference_type n)
        {
            ptr_ -= n * iter_stride_;
            return *this;
        }

        RowAndColIterator operator*() const { return *this; }

        RowAndColIterator operator+(const difference_type n) const { return RowAndColIterator{ptr_ + n * iter_stride_, iter_stride_, value_iter_stride_, value_iter_end_dist_}; }
        RowAndColIterator operator-(const difference_type n) const { return RowAndColIterator{ptr_ - n * iter_stride_, iter_stride_, value_iter_stride_, value_iter_end_dist_}; }

        friend bool operator==(const RowAndColIterator& a, const RowAndColIterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!=(const RowAndColIterator& a, const RowAndColIterator& b) { return a.ptr_ != b.ptr_; };

        ValueIterator begin() { return ValueIterator{ptr_, value_iter_stride_}; }
        ValueIterator end() { return ValueIterator{ptr_ + value_iter_end_dist_, value_iter_stride_}; }

    private:
        pointer ptr_;
        difference_type iter_stride_;
        difference_type value_iter_stride_;
        difference_type value_iter_end_dist_;
    };

    class Rows {
    public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;

        Rows(pointer begin, pointer end, const difference_type row_width) : begin_{begin}, end_{end}, row_width_{row_width} { }

        RowAndColIterator begin() { return RowAndColIterator{begin_, row_width_, 1, row_width_}; }
        RowAndColIterator end() { return RowAndColIterator{end_, row_width_, 1, row_width_}; }

    private:
        pointer begin_;
        pointer end_;
        difference_type row_width_;
    };

    class Cols {
    public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;

        Cols(pointer begin, pointer end, const difference_type row_width, const difference_type col_height) : begin_{begin}, end_{end}, row_width_{row_width}, col_height_{col_height} { }

        RowAndColIterator begin() { return RowAndColIterator{begin_, 1, row_width_, row_width_ * col_height_}; }
        RowAndColIterator end() { return RowAndColIterator{end_, 1, row_width_, row_width_ * col_height_}; }

    private:
        pointer begin_;
        pointer end_;
        difference_type row_width_;
        difference_type col_height_;
    };

    using value_type = T;

    Grid(int cols, int rows);
    Grid(int cols, int rows, const T& value);

    [[nodiscard]] int width() const { return cols_; }
    [[nodiscard]] int height() const { return rows_; }

    [[nodiscard]] T* data() { return data_.data(); }
    [[nodiscard]] std::size_t size() const { return data_.size(); }

    [[nodiscard]] T& value(int col, int row);
    [[nodiscard]] const T& value(int col, int row) const;

    [[nodiscard]] T& value(const Coords& coords);
    [[nodiscard]] const T& value(const Coords& coords) const;

    [[nodiscard]] GridCell<T> cell(int col, int row);
    [[nodiscard]] GridCell<T> cell(const Coords& coords);

    [[nodiscard]] auto begin() noexcept { return data_.begin(); };
    [[nodiscard]] auto end() noexcept { return data_.end(); };
    [[nodiscard]] auto cbegin() const noexcept { return data_.cbegin(); };
    [[nodiscard]] auto cend() const noexcept { return data_.cend(); };
    [[nodiscard]] auto rbegin() noexcept { return data_.rbegin(); };
    [[nodiscard]] auto rend() noexcept { return data_.rend(); };
    [[nodiscard]] auto crbegin() const noexcept { return data_.crbegin(); };
    [[nodiscard]] auto crend() const noexcept { return data_.crend(); };

    [[nodiscard]] auto rows() { return Rows(data(), data() + size(), width()); }
    [[nodiscard]] auto cols() { return Cols(data(), data() + width(), width(), height()); }

    [[nodiscard]] auto row(const int n) { return rows().begin() + n; }
    [[nodiscard]] auto col(const int n) { return cols().begin() + n; }

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
    assert(idx(col, row) < size());

    return data_[idx(col, row)];
}

template <typename T>
const T& Grid<T>::value(const int col, const int row) const
{
    assert(col >= 0 && row >= 0);
    assert(idx(col, row) < size());

    return data_[idx(col, row)];
}

template <typename T>
T& Grid<T>::value(const Coords& coords)
{
    assert(coords.x >= 0 && coords.y >= 0);
    assert(idx(coords) < size());

    return data_[idx(coords)];
}

template <typename T>
const T& Grid<T>::value(const Coords& coords) const
{
    assert(coords.x >= 0 && coords.y >= 0);
    assert(idx(coords) < size());

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
