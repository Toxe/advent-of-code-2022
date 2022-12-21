#include <algorithm>
#include <numeric>

#include "catch2/catch_test_macros.hpp"

#include "grid.hpp"

Grid<int> create_grid_with_numbered_values(int cols, int rows)
{
    Grid<int> grid{cols, rows};

    for (int row = 0; row < rows; ++row)
        for (int col = 0; col < cols; ++col)
            grid.value(col, row) = row * cols + col + 1;

    return grid;
}

int sum_values(Grid<int>::RowAndColIterator iter)
{
    int sum = 0;

    for (const int i : iter)
        sum += i;

    return sum;
}

TEST_CASE("Grid")
{
    SECTION("can create new Grid with default initialized elements")
    {
        const Grid<int> grid{3, 4};

        REQUIRE(grid.width() == 3);
        REQUIRE(grid.height() == 4);

        CHECK(grid.value(0, 0) == 0);
        CHECK(grid.value(1, 2) == 0);
        CHECK(grid.value(2, 1) == 0);
        CHECK(grid.value(2, 3) == 0);
    }

    SECTION("can create new Grid with element values")
    {
        const Grid<int> grid{3, 4, -1};

        REQUIRE(grid.width() == 3);
        REQUIRE(grid.height() == 4);

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
        const Grid<int> grid{3, 3};

        CHECK(grid.value(1, 2) == 0);
        CHECK(grid.value(Coords{1, 2}) == 0);
    }

    SECTION("size() returns the correct number of Grid elements")
    {
        const Grid<int> grid{5, 6};

        CHECK(grid.size() == 30);
    }

    SECTION("data() returns a pointer to the first value")
    {
        Grid<int> grid{5, 6};
        grid.value(0, 0) = 42;

        CHECK(*(grid.data()) == 42);
    }

    SECTION("iterate all values")
    {
        SECTION("const")
        {
            const Grid<int> grid = create_grid_with_numbered_values(4, 5);

            SECTION("sum first 12 values with cbegin()/cend()")
            {
                CHECK(std::accumulate(grid.cbegin(), grid.cend() - 12, 0) == 36);
            }

            SECTION("sum last 12 values with crbegin()/crend()")
            {
                CHECK(std::accumulate(grid.crbegin(), grid.crend() - 12, 0) == 132);
            }
        }

        SECTION("non-const")
        {
            Grid<int> grid = create_grid_with_numbered_values(4, 5);

            SECTION("sum first 12 values with begin()/end()")
            {
                CHECK(std::accumulate(grid.begin(), grid.end() - 12, 0) == 36);
            }

            SECTION("sum last 12 values with rbegin()/rend()")
            {
                CHECK(std::accumulate(grid.rbegin(), grid.rend() - 12, 0) == 132);
            }
        }
    }

    SECTION("iterate rows")
    {
        Grid<int> grid = create_grid_with_numbered_values(4, 5);

        SECTION("traditional for loop")
        {
            int sum = 0;

            for (auto row = grid.rows().begin(); row != grid.rows().end(); ++row)
                for (auto it = row.begin(); it != row.end(); ++it)
                    sum += *it;

            CHECK(sum == 210);
        }

        SECTION("range-based for loop")
        {
            int sum = 0;

            for (auto row : grid.rows())
                for (const int i : row)
                    sum += i;

            CHECK(sum == 210);
        }

        SECTION("access single row")
        {
            CHECK(sum_values(grid.row(2)) == 42);
        }

        SECTION("row iterator")
        {
            SECTION("operator++")
            {
                auto row = grid.rows().begin();

                CHECK(sum_values(++row) == 26);
                CHECK(sum_values(row++) == 26);
                CHECK(sum_values(row++) == 42);
            }

            SECTION("operator--")
            {
                auto row = grid.rows().end();

                CHECK(sum_values(--row) == 74);
                CHECK(sum_values(row--) == 74);
                CHECK(sum_values(row--) == 58);
            }

            SECTION("operator+=")
            {
                auto row = grid.rows().begin();
                row += 2;

                CHECK(sum_values(row) == 42);
            }

            SECTION("operator-=")
            {
                auto row = grid.rows().end();
                row -= 3;

                CHECK(sum_values(row) == 42);
            }

            SECTION("operator+")
            {
                CHECK(sum_values(grid.rows().begin() + 2) == 42);
            }

            SECTION("operator-")
            {
                CHECK(sum_values(grid.rows().end() - 3) == 42);
            }

            SECTION("std::next")
            {
                auto row = grid.rows().begin();

                CHECK(*(std::next(row).begin()) == 5);
                CHECK(*(std::next(row, 3).begin()) == 13);
            }

            SECTION("std::prev")
            {
                auto row = grid.rows().end();

                CHECK(*(std::prev(row).begin()) == 17);
                CHECK(*(std::prev(row, 3).begin()) == 9);
            }

            SECTION("std::advance")
            {
                auto row = grid.rows().begin();

                std::advance(row, 1);
                CHECK(*(row.begin()) == 5);

                std::advance(row, 2);
                CHECK(*(row.begin()) == 13);
            }

            SECTION("std::distance")
            {
                CHECK(std::distance(grid.rows().begin(), grid.rows().end()) == 5);
            }
        }

        SECTION("row value iterator")
        {
            SECTION("operator++")
            {
                auto it = grid.row(2).begin();

                CHECK(*(++it) == 10);
                CHECK(*(it++) == 10);
                CHECK(*(it++) == 11);
            }

            SECTION("operator--")
            {
                auto it = grid.row(2).end();

                CHECK(*(--it) == 12);
                CHECK(*(it--) == 12);
                CHECK(*(it--) == 11);
            }

            SECTION("operator+=")
            {
                auto it = grid.row(2).begin();
                it += 2;

                CHECK(*it == 11);
            }

            SECTION("operator-=")
            {
                auto it = grid.row(2).end();
                it -= 3;

                CHECK(*it == 10);
            }

            SECTION("operator+")
            {
                CHECK(*(grid.row(2).begin() + 2) == 11);
            }

            SECTION("operator-")
            {
                CHECK(*(grid.row(2).end() - 3) == 10);
            }

            SECTION("distance between elements")
            {
                auto p1 = grid.row(2).begin();
                auto p2 = grid.row(2).end();

                CHECK(p1 - p1 == 0);
                CHECK(p1 - (p1 + 1) == 1);
                CHECK(p1 - (p1 + 2) == 2);
                CHECK(p1 - (p1 + 3) == 3);
                CHECK((p1 + 1) - p1 == 1);
                CHECK((p1 + 2) - p1 == 2);
                CHECK((p1 + 3) - p1 == 3);
                CHECK(p1 - p2 == 4);
                CHECK(p2 - p1 == 4);
            }

            SECTION("std::next")
            {
                auto it = grid.row(1).begin();

                CHECK(*std::next(it) == 6);
                CHECK(*std::next(it, 3) == 8);
            }

            SECTION("std::prev")
            {
                auto it = grid.row(1).end();

                CHECK(*std::prev(it) == 8);
                CHECK(*std::prev(it, 3) == 6);
            }

            SECTION("std::advance")
            {
                auto it = grid.row(1).begin();

                std::advance(it, 1);
                CHECK(*it == 6);

                std::advance(it, 2);
                CHECK(*it == 8);
            }

            SECTION("std::distance")
            {
                CHECK(std::distance(grid.row(1).begin(), grid.row(1).end()) == 4);
            }
        }

        SECTION("std::accumulate")
        {
            auto row = grid.row(2);

            CHECK(std::accumulate(row.begin(), row.end(), 0) == 42);
        }

        SECTION("std::find")
        {
            auto row = grid.row(2);

            CHECK(std::find(row.begin(), row.end(), 10) != row.end());
            CHECK(std::find(row.begin(), row.end(), 99) == row.end());
        }
    }

    SECTION("iterate columns")
    {
        Grid<int> grid = create_grid_with_numbered_values(4, 5);

        SECTION("traditional for loop")
        {
            int sum = 0;

            for (auto col = grid.cols().begin(); col != grid.cols().end(); ++col)
                for (auto it = col.begin(); it != col.end(); ++it)
                    sum += *it;

            CHECK(sum == 210);
        }

        SECTION("range-based for loop")
        {
            int sum = 0;

            for (auto col : grid.cols())
                for (const int i : col)
                    sum += i;

            CHECK(sum == 210);
        }

        SECTION("access single column")
        {
            CHECK(sum_values(grid.col(2)) == 55);
        }

        SECTION("column iterator")
        {
            SECTION("operator++")
            {
                auto col = grid.cols().begin();

                CHECK(sum_values(++col) == 50);
                CHECK(sum_values(col++) == 50);
                CHECK(sum_values(col++) == 55);
            }

            SECTION("operator--")
            {
                auto col = grid.cols().end();

                CHECK(sum_values(--col) == 60);
                CHECK(sum_values(col--) == 60);
                CHECK(sum_values(col--) == 55);
            }

            SECTION("operator+=")
            {
                auto col = grid.cols().begin();
                col += 2;

                CHECK(sum_values(col) == 55);
            }

            SECTION("operator-=")
            {
                auto col = grid.cols().end();
                col -= 3;

                CHECK(sum_values(col) == 50);
            }

            SECTION("operator+")
            {
                CHECK(sum_values(grid.cols().begin() + 2) == 55);
            }

            SECTION("operator-")
            {
                CHECK(sum_values(grid.cols().end() - 3) == 50);
            }

            SECTION("std::next")
            {
                auto col = grid.cols().begin();

                CHECK(*(std::next(col).begin()) == 2);
                CHECK(*(std::next(col, 3).begin()) == 4);
            }

            SECTION("std::prev")
            {
                auto col = grid.cols().end();

                CHECK(*(std::prev(col).begin()) == 4);
                CHECK(*(std::prev(col, 3).begin()) == 2);
            }

            SECTION("std::advance")
            {
                auto col = grid.cols().begin();

                std::advance(col, 1);
                CHECK(*(col.begin()) == 2);

                std::advance(col, 2);
                CHECK(*(col.begin()) == 4);
            }

            SECTION("std::distance")
            {
                CHECK(std::distance(grid.cols().begin(), grid.cols().end()) == 4);
            }
        }

        SECTION("column value iterator")
        {
            SECTION("operator++")
            {
                auto it = grid.col(2).begin();

                CHECK(*(++it) == 7);
                CHECK(*(it++) == 7);
                CHECK(*(it++) == 11);
            }

            SECTION("operator--")
            {
                auto it = grid.col(2).end();

                CHECK(*(--it) == 19);
                CHECK(*(it--) == 19);
                CHECK(*(it--) == 15);
            }

            SECTION("operator+=")
            {
                auto it = grid.col(2).begin();
                it += 2;

                CHECK(*it == 11);
            }

            SECTION("operator-=")
            {
                auto it = grid.col(2).end();
                it -= 3;

                CHECK(*it == 11);
            }

            SECTION("operator+")
            {
                CHECK(*(grid.col(2).begin() + 2) == 11);
            }

            SECTION("operator-")
            {
                CHECK(*(grid.col(2).end() - 3) == 11);
            }

            SECTION("distance between elements")
            {
                auto p1 = grid.col(2).begin();
                auto p2 = grid.col(2).end();

                CHECK(p1 - p1 == 0);
                CHECK(p1 - (p1 + 1) == 1);
                CHECK(p1 - (p1 + 2) == 2);
                CHECK(p1 - (p1 + 3) == 3);
                CHECK(p1 - (p1 + 4) == 4);
                CHECK((p1 + 1) - p1 == 1);
                CHECK((p1 + 2) - p1 == 2);
                CHECK((p1 + 3) - p1 == 3);
                CHECK((p1 + 4) - p1 == 4);
                CHECK(p1 - p2 == 5);
                CHECK(p2 - p1 == 5);
            }

            SECTION("std::next")
            {
                auto it = grid.col(1).begin();

                CHECK(*std::next(it) == 6);
                CHECK(*std::next(it, 3) == 14);
            }

            SECTION("std::prev")
            {
                auto it = grid.col(1).end();

                CHECK(*std::prev(it) == 18);
                CHECK(*std::prev(it, 3) == 10);
            }

            SECTION("std::advance")
            {
                auto it = grid.col(1).begin();

                std::advance(it, 1);
                CHECK(*it == 6);

                std::advance(it, 2);
                CHECK(*it == 14);
            }

            SECTION("std::distance")
            {
                CHECK(std::distance(grid.col(1).begin(), grid.col(1).end()) == 5);
            }
        }

        SECTION("std::accumulate")
        {
            auto col = grid.col(2);

            CHECK(std::accumulate(col.begin(), col.end(), 0) == 55);
        }

        SECTION("std::find")
        {
            auto col = grid.col(2);

            CHECK(std::find(col.begin(), col.end(), 11) != col.end());
            CHECK(std::find(col.begin(), col.end(), 99) == col.end());
        }
    }
}
