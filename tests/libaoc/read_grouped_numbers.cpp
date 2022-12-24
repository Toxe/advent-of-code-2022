#include <sstream>

#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_container_properties.hpp"

#include "read_grouped_numbers.hpp"

TEST_CASE("libaoc: read_grouped_numbers()")
{
    SECTION("reads all groups and numbers")
    {
        std::istringstream input{
            "1\n"
            "2\n"
            "3\n"
            "\n"
            "4\n"
            "5\n"
            "\n"
            "6"};

        const auto grouped_numbers = read_grouped_numbers(input);

        CHECK_THAT(grouped_numbers, Catch::Matchers::SizeIs(3));
        CHECK_THAT(grouped_numbers[0], Catch::Matchers::SizeIs(3));
        CHECK_THAT(grouped_numbers[1], Catch::Matchers::SizeIs(2));
        CHECK_THAT(grouped_numbers[2], Catch::Matchers::SizeIs(1));
        CHECK(grouped_numbers[0][0] == 1);
        CHECK(grouped_numbers[0][1] == 2);
        CHECK(grouped_numbers[0][2] == 3);
        CHECK(grouped_numbers[1][0] == 4);
        CHECK(grouped_numbers[1][1] == 5);
        CHECK(grouped_numbers[2][0] == 6);
    }

    SECTION("ignores superfluous newlines")
    {
        std::istringstream input{
            "\n"
            "1\n"
            "2\n"
            "3\n"
            "\n"
            "\n"
            "4\n"
            "5\n"
            "\n"
            "\n"
            "6\n"
            "\n"
            "\n"};

        const auto grouped_numbers = read_grouped_numbers(input);

        CHECK_THAT(grouped_numbers, Catch::Matchers::SizeIs(3));
        CHECK_THAT(grouped_numbers[0], Catch::Matchers::SizeIs(3));
        CHECK_THAT(grouped_numbers[1], Catch::Matchers::SizeIs(2));
        CHECK_THAT(grouped_numbers[2], Catch::Matchers::SizeIs(1));
        CHECK(grouped_numbers[0][0] == 1);
        CHECK(grouped_numbers[0][1] == 2);
        CHECK(grouped_numbers[0][2] == 3);
        CHECK(grouped_numbers[1][0] == 4);
        CHECK(grouped_numbers[1][1] == 5);
        CHECK(grouped_numbers[2][0] == 6);
    }

    SECTION("throws exception for bad input")
    {
        std::istringstream input{
            "1\n"
            "two"};

        CHECK_THROWS(read_grouped_numbers(input));
    }
}
