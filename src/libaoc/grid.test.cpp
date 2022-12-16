#include "catch2/catch_test_macros.hpp"

#include "grid.hpp"

TEST_CASE("Grid")
{
    SECTION("can create new Grid with default initialized elements")
    {
        const Grid<int> grid{3, 4};

        REQUIRE(grid.rows() == 3);
        REQUIRE(grid.cols() == 4);

        CHECK(grid.value(0, 0) == 0);
        CHECK(grid.value(1, 2) == 0);
        CHECK(grid.value(2, 1) == 0);
        CHECK(grid.value(2, 3) == 0);
    }

    SECTION("can create new Grid with element values")
    {
        const Grid<int> grid{3, 4, -1};

        REQUIRE(grid.rows() == 3);
        REQUIRE(grid.cols() == 4);

        CHECK(grid.value(0, 0) == -1);
        CHECK(grid.value(1, 2) == -1);
        CHECK(grid.value(2, 1) == -1);
        CHECK(grid.value(2, 3) == -1);
    }

    SECTION("can change elements")
    {
        Grid<int> grid{4, 4};

        grid.value(0, 0) = 1;
        grid.value(1, 2) = 2;
        grid.value(2, 1) = 3;
        grid.value(3, 3) = 4;

        CHECK(grid.value(0, 0) == 1);
        CHECK(grid.value(1, 2) == 2);
        CHECK(grid.value(2, 1) == 3);
        CHECK(grid.value(3, 3) == 4);
    }
}
