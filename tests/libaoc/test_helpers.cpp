#include "catch2/catch_test_macros.hpp"

#include "test_helpers.hpp"

TEST_CASE("libaoc: TempFile")
{
    SECTION("creates a file and automatically deletes it")
    {
        std::string filename;

        {
            const TempFile tmp;
            filename = tmp.name;

            CHECK(std::filesystem::exists(filename));
        }

        CHECK(std::filesystem::exists(filename) == false);
    }
}
