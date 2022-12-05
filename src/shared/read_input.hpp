#pragma once

#include <fstream>
#include <istream>
#include <optional>
#include <span>
#include <string>
#include <vector>

std::optional<std::ifstream> open_input_file(std::span<const char*> args);
std::vector<std::string> read_lines_and_preserve_empty_lines(std::istream& input);
std::vector<std::string> read_lines_and_remove_empty_lines(std::istream& input);
