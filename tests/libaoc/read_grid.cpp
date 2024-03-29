#include <sstream>

#include "catch2/catch_test_macros.hpp"

#include "read_grid.hpp"

void check_grid_values(const ByteGrid& grid)
{
    CHECK(grid.at(0, 0) == 1);
    CHECK(grid.at(1, 0) == 2);
    CHECK(grid.at(2, 0) == 3);
    CHECK(grid.at(3, 0) == 4);
    CHECK(grid.at(0, 1) == 5);
    CHECK(grid.at(1, 1) == 6);
    CHECK(grid.at(2, 1) == 7);
    CHECK(grid.at(3, 1) == 8);
    CHECK(grid.at(0, 2) == 3);
    CHECK(grid.at(1, 2) == 4);
    CHECK(grid.at(2, 2) == 5);
    CHECK(grid.at(3, 2) == 6);
}

TEST_CASE("libaoc: read_digit_grid()")
{
    SECTION("reads all digits")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456\n"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.width() == 4);
        CHECK(grid.height() == 3);

        check_grid_values(grid);
    }

    SECTION("ignores newlines at the end")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456\n\n\n\n"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.width() == 4);
        CHECK(grid.height() == 3);

        check_grid_values(grid);
    }

    SECTION("does not need a newline at the end")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.width() == 4);
        CHECK(grid.height() == 3);

        check_grid_values(grid);
    }

    SECTION("stops reading height after a newline")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456\n"
            "\n"
            "1234\n"
            "5678\n"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.width() == 4);
        CHECK(grid.height() == 3);

        check_grid_values(grid);
    }

    SECTION("throws exception for bad input values")
    {
        std::istringstream input{
            "13a\n"
            "two\n"};

        CHECK_THROWS(read_digit_grid(input));
    }

    SECTION("throws exception if column sizes differ")
    {
        std::istringstream input1{
            "1234\n"
            "567\n"
            "3456\n"};

        std::istringstream input2{
            "1234\n"
            "56789\n"
            "3456\n"};

        CHECK_THROWS(read_digit_grid(input1));
        CHECK_THROWS(read_digit_grid(input2));
    }
}
