#pragma once

#include <fstream>
#include <optional>
#include <span>

std::optional<std::ifstream> open_input_file(std::span<const char*> args);
