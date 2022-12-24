#include "catch2/catch_test_macros.hpp"

#include "grid.hpp"
#include "gridcell.hpp"

TEST_CASE("libaoc: GridCell")
{
    SECTION("can get coordinates")
    {
        Grid<int> grid{4, 4};
        auto cell1 = grid.cell(1, 2);
        auto cell2 = grid.cell(Coords{2, 3});

        CHECK(cell1.x == 1);
        CHECK(cell1.y == 2);
        CHECK(cell1.col() == 1);
        CHECK(cell1.row() == 2);
        CHECK(cell1.coords() == Coords{1, 2});

        CHECK(cell2.x == 2);
        CHECK(cell2.y == 3);
        CHECK(cell2.col() == 2);
        CHECK(cell2.row() == 3);
        CHECK(cell2.coords() == Coords{2, 3});
    }

    SECTION("can access and change values")
    {
        Grid<int> grid{4, 4};
        auto cell1 = grid.cell(1, 2);
        auto cell2 = grid.cell(Coords{2, 3});

        cell1.value() = 5;
        cell2.value() = 9;

        CHECK(grid.value(1, 2) == 5);
        CHECK(grid.value(2, 3) == 9);
    }

    SECTION("const access")
    {
        Grid<int> grid{4, 4};
        const auto cell = grid.cell(1, 2);

        CHECK(cell.value() == 0);
    }

    SECTION("can move cell")
    {
        Grid<int> grid{4, 4};
        auto cell = grid.cell(1, 2);

        cell.move_up(2);
        cell.value() = 3;
        CHECK(grid.value(1, 0) == 3);

        cell.move_horizontally(2);
        cell.value() = 5;
        CHECK(grid.value(3, 0) == 5);

        cell.move(-2, 3);
        cell.value() = 7;
        CHECK(grid.value(1, 3) == 7);
    }
}
