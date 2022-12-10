#include "read_input.hpp"

#include <filesystem>
#include <iostream>

std::optional<std::string> get_input_filename(const std::span<const char*>& args)
{
    if (args.size() < 2) {
        std::cerr << "missing input file name\n";
        return std::nullopt;
    }

    return args[1];
}

std::optional<std::ifstream> open_input_file(const std::optional<std::string>& input_filename)
{
    if (!input_filename)
        return std::nullopt;

    if (!std::filesystem::exists(*input_filename)) {
        std::cerr << "input file not found: " << *input_filename << '\n';
        return std::nullopt;
    }

    std::ifstream input_stream{*input_filename};

    if (!input_stream.is_open()) {
        std::cerr << "unable to open file: " << *input_filename << '\n';
        return std::nullopt;
    }

    return input_stream;
}

std::string read_single_line(std::istream& input)
{
    std::string line;

    std::getline(input, line);

    return line;
}

std::vector<std::string> read_lines_and_preserve_empty_lines(std::istream& input)
{
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line))
        lines.push_back(line);

    return lines;
}

std::vector<std::string> read_lines_and_remove_empty_lines(std::istream& input)
{
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line))
        if (!line.empty())
            lines.push_back(line);

    return lines;
}
