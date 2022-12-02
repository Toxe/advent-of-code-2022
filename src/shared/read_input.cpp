#include "read_input.hpp"

#include <filesystem>
#include <iostream>

std::optional<std::ifstream> open_input_file(std::span<const char*> args)
{
    if (args.size() < 2) {
        std::cerr << "missing input file name\n";
        return std::nullopt;
    }

    if (!std::filesystem::exists(args[1])) {
        std::cerr << "input file not found: " << args[1] << '\n';
        return std::nullopt;
    }

    std::ifstream file{args[1]};

    if (!file.is_open()) {
        std::cerr << "unable to open file: " << args[1] << '\n';
        return std::nullopt;
    }

    return file;
}
