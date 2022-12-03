#if _WIN32 || _WIN64
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <filesystem>
#include <sstream>
#include <vector>

#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_container_properties.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "read_input.hpp"

struct TempFile {
    TempFile() : name(tmpnam(nullptr))
    {
        file = std::ofstream{name, std::ios::binary};
    }

    ~TempFile()
    {
        if (file.is_open()) {
            file.close();
            std::filesystem::remove(name);
        }
    }

    std::string name;
    std::ofstream file;
};

TEST_CASE("open_input_file()")
{
    SECTION("needs at least two command line arguments")
    {
        std::vector<const char*> args{"program"};
        auto input_file = open_input_file(args);

        CHECK(input_file.has_value() == false);
    }

    SECTION("returns an open input file stream")
    {
        TempFile tmpfile;

        std::vector<const char*> args{"program", tmpfile.name.data()};
        auto input_file = open_input_file(args);

        CHECK(input_file.has_value());
        CHECK(input_file->is_open());
    }

    SECTION("file must exist")
    {
        const char* tmp_filename = tmpnam(nullptr);

        std::vector<const char*> args{"program", tmp_filename};
        auto input_file = open_input_file(args);

        CHECK(input_file.has_value() == false);
    }
}

TEST_CASE("read_lines()")
{
    SECTION("reads all lines")
    {
        std::istringstream input{
            "line 1\n"
            "line 2\n"
            "line 3"};

        const auto lines = read_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(3));
        CHECK_THAT(lines[0], Catch::Matchers::Equals("line 1"));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("line 2"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals("line 3"));
    }

    SECTION("ignores newlines")
    {
        std::istringstream input{
            "\n"
            "aaa\n"
            "\n"
            "\n"
            "bbb\n"
            "\n"
            "ccc"
            "\n"
            "\n"};

        const auto lines = read_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(3));
        CHECK_THAT(lines[0], Catch::Matchers::Equals("aaa"));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("bbb"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals("ccc"));
    }
}
