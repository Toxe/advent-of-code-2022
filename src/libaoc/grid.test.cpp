#include "catch2/catch_test_macros.hpp"

#include "grid.hpp"

TEST_CASE("Grid")
{
    SECTION("can create new Grid with default initialized elements")
    {
        const Grid<int> grid{3, 4};

        REQUIRE(grid.cols() == 3);
        REQUIRE(grid.rows() == 4);

        CHECK(grid.value(0, 0) == 0);
        CHECK(grid.value(1, 2) == 0);
        CHECK(grid.value(2, 1) == 0);
        CHECK(grid.value(2, 3) == 0);
    }

    SECTION("can create new Grid with element values")
    {
        const Grid<int> grid{3, 4, -1};

        REQUIRE(grid.cols() == 3);
        REQUIRE(grid.rows() == 4);

        CHECK(grid.value(0, 0) == -1);
        CHECK(grid.value(1, 2) == -1);
        CHECK(grid.value(2, 1) == -1);
        CHECK(grid.value(2, 3) == -1);
    }

    SECTION("can access and change values")
    {
        Grid<int> a{4, 4};
        Grid<int> b{4, 4};

        a.value(0, 0) = 1;
        a.value(1, 2) = 2;
        a.value(2, 1) = 3;
        a.value(3, 3) = 4;

        b.value(Coords{0, 0}) = 11;
        b.value(Coords{1, 2}) = 12;
        b.value(Coords{2, 1}) = 13;
        b.value(Coords{3, 3}) = 14;

        CHECK(a.value(0, 0) == 1);
        CHECK(a.value(1, 2) == 2);
        CHECK(a.value(2, 1) == 3);
        CHECK(a.value(3, 3) == 4);

        CHECK(b.value(Coords{0, 0}) == 11);
        CHECK(b.value(Coords{1, 2}) == 12);
        CHECK(b.value(Coords{2, 1}) == 13);
        CHECK(b.value(Coords{3, 3}) == 14);
    }

    SECTION("const access")
    {
        const Grid<int> c{3, 3};

        CHECK(c.value(1, 2) == 0);
        CHECK(c.value(Coords{1, 2}) == 0);
    }
}
