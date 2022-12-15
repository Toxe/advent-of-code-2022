#include <sstream>
#include <vector>

#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers_container_properties.hpp"
#include "catch2/matchers/catch_matchers_string.hpp"

#include "read_input.hpp"
#include "test_helpers.hpp"

TEST_CASE("file_exists()")
{
    SECTION("returns true if file exists")
    {
        const TempFile tmpfile;

        CHECK(file_exists(tmpfile.name));
    }

    SECTION("returns false if file does not exist")
    {
        const char* tmp_filename = std::tmpnam(nullptr);

        CHECK(file_exists(tmp_filename) == false);
    }
}

TEST_CASE("get_input_filename()")
{
    SECTION("needs at least two command line arguments")
    {
        std::vector<const char*> args{"program"};
        const auto input_filename = get_input_filename(args);

        CHECK(input_filename.has_value() == false);
    }
}

TEST_CASE("open_input_file()")
{
    SECTION("returns an open input file stream")
    {
        TempFile tmpfile;

        std::vector<const char*> args{"program", tmpfile.name.data()};
        const auto input_filename = get_input_filename(args);
        auto input_stream = open_input_file(input_filename);

        CHECK(input_stream.has_value());
        CHECK(input_stream->is_open());
    }

    SECTION("file must exist")
    {
        const char* tmp_filename = std::tmpnam(nullptr);

        std::vector<const char*> args{"program", tmp_filename};
        const auto input_filename = get_input_filename(args);
        auto input_stream = open_input_file(input_filename);

        CHECK(input_stream.has_value() == false);
    }
}

TEST_CASE("read_single_line()")
{
    SECTION("reads one line")
    {
        std::istringstream input{"line"};

        CHECK_THAT(read_single_line(input), Catch::Matchers::Equals("line"));
    }

    SECTION("handles newline at the end")
    {
        std::istringstream input{"line\n"};

        CHECK_THAT(read_single_line(input), Catch::Matchers::Equals("line"));
    }

    SECTION("ignores additional empty lines and newlines")
    {
        std::istringstream input{"line\n\n\n"};

        CHECK_THAT(read_single_line(input), Catch::Matchers::Equals("line"));
    }

    SECTION("reads only the first line")
    {
        std::istringstream input{
            "line\n"
            "line 2\n"
            "line 3\n"};

        CHECK_THAT(read_single_line(input), Catch::Matchers::Equals("line"));
    }
}

TEST_CASE("read_lines_and_preserve_empty_lines()")
{
    SECTION("reads all lines")
    {
        std::istringstream input{
            "line 1\n"
            "line 2\n"
            "line 3"};

        const auto lines = read_lines_and_preserve_empty_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(3));
        CHECK_THAT(lines[0], Catch::Matchers::Equals("line 1"));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("line 2"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals("line 3"));
    }

    SECTION("handles newline in last line")
    {
        std::istringstream input{
            "line 1\n"
            "line 2\n"
            "line 3\n"};

        const auto lines = read_lines_and_preserve_empty_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(3));
        CHECK_THAT(lines[0], Catch::Matchers::Equals("line 1"));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("line 2"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals("line 3"));
    }

    SECTION("preserves empty lines")
    {
        std::istringstream input{
            "\n"
            "aaa\n"
            "\n"
            "\n"
            "bbb\n"
            "\n"
            "ccc\n"
            "\n"
            "\n"};

        const auto lines = read_lines_and_preserve_empty_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(9));
        CHECK_THAT(lines[0], Catch::Matchers::Equals(""));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("aaa"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals(""));
        CHECK_THAT(lines[3], Catch::Matchers::Equals(""));
        CHECK_THAT(lines[4], Catch::Matchers::Equals("bbb"));
        CHECK_THAT(lines[5], Catch::Matchers::Equals(""));
        CHECK_THAT(lines[6], Catch::Matchers::Equals("ccc"));
        CHECK_THAT(lines[7], Catch::Matchers::Equals(""));
        CHECK_THAT(lines[8], Catch::Matchers::Equals(""));
    }
}

TEST_CASE("read_lines_and_remove_empty_lines()")
{
    SECTION("reads all lines")
    {
        std::istringstream input{
            "line 1\n"
            "line 2\n"
            "line 3"};

        const auto lines = read_lines_and_remove_empty_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(3));
        CHECK_THAT(lines[0], Catch::Matchers::Equals("line 1"));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("line 2"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals("line 3"));
    }

    SECTION("handles newline in last line")
    {
        std::istringstream input{
            "line 1\n"
            "line 2\n"
            "line 3\n"};

        const auto lines = read_lines_and_remove_empty_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(3));
        CHECK_THAT(lines[0], Catch::Matchers::Equals("line 1"));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("line 2"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals("line 3"));
    }

    SECTION("removes empty lines")
    {
        std::istringstream input{
            "\n"
            "aaa\n"
            "\n"
            "\n"
            "bbb\n"
            "\n"
            "ccc\n"
            "\n"
            "\n"};

        const auto lines = read_lines_and_remove_empty_lines(input);

        CHECK_THAT(lines, Catch::Matchers::SizeIs(3));
        CHECK_THAT(lines[0], Catch::Matchers::Equals("aaa"));
        CHECK_THAT(lines[1], Catch::Matchers::Equals("bbb"));
        CHECK_THAT(lines[2], Catch::Matchers::Equals("ccc"));
    }
}
