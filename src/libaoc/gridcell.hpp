#pragma once

#include "coords.hpp"

template <typename T>
class Grid;

template <typename T>
class GridCell : public Coords {
public:
    using value_type = T;

    GridCell(Grid<T>* grid, const Coords& coords) : Coords(coords), grid_{grid} { }

    [[nodiscard]] int col() const { return x; }
    [[nodiscard]] int row() const { return y; }
    [[nodiscard]] Coords coords() const { return {x, y}; }

    [[nodiscard]] T& value() { return grid_->value(x, y); }
    [[nodiscard]] const T& value() const { return grid_->value(x, y); }

private:
    Grid<T>* grid_;
};
