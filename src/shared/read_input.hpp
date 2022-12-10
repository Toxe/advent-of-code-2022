#pragma once

#include <fstream>
#include <istream>
#include <optional>
#include <span>
#include <string>
#include <vector>

bool file_exists(const std::string& filename);
std::optional<std::string> get_input_filename(const std::span<const char*>& args);
std::optional<std::ifstream> open_input_file(const std::optional<std::string>& input_filename);

std::string read_single_line(std::istream& input);
std::vector<std::string> read_lines_and_preserve_empty_lines(std::istream& input);
std::vector<std::string> read_lines_and_remove_empty_lines(std::istream& input);
