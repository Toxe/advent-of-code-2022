#include <sstream>

#include "catch2/catch_test_macros.hpp"

#include "read_grid.hpp"

void check_grid_values(const ByteGrid& grid)
{
    CHECK(grid.value(0, 0) == 1);
    CHECK(grid.value(0, 1) == 2);
    CHECK(grid.value(0, 2) == 3);
    CHECK(grid.value(0, 3) == 4);
    CHECK(grid.value(1, 0) == 5);
    CHECK(grid.value(1, 1) == 6);
    CHECK(grid.value(1, 2) == 7);
    CHECK(grid.value(1, 3) == 8);
    CHECK(grid.value(2, 0) == 3);
    CHECK(grid.value(2, 1) == 4);
    CHECK(grid.value(2, 2) == 5);
    CHECK(grid.value(2, 3) == 6);
}

TEST_CASE("read_digit_grid()")
{
    SECTION("reads all digits")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456\n"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.rows() == 3);
        CHECK(grid.cols() == 4);

        check_grid_values(grid);
    }

    SECTION("ignores newlines at the end")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456\n\n\n\n"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.rows() == 3);
        CHECK(grid.cols() == 4);

        check_grid_values(grid);
    }

    SECTION("does not need a newline at the end")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.rows() == 3);
        CHECK(grid.cols() == 4);

        check_grid_values(grid);
    }

    SECTION("stops reading rows after a newline")
    {
        std::istringstream input{
            "1234\n"
            "5678\n"
            "3456\n"
            "\n"
            "1234\n"
            "5678\n"};

        const auto grid = read_digit_grid(input);

        CHECK(grid.rows() == 3);
        CHECK(grid.cols() == 4);

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
