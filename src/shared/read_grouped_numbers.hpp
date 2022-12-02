#pragma once

#include <istream>
#include <vector>

using GroupedNumbers = std::vector<std::vector<int>>;

GroupedNumbers read_grouped_numbers(std::istream& input);
