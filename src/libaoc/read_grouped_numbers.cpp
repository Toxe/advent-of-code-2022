#include "read_grouped_numbers.hpp"

#include <string>

GroupedNumbers read_grouped_numbers(std::istream& input)
{
    GroupedNumbers grouped_numbers;
    std::vector<int> current_group;
    std::string line;

    while (std::getline(input, line)) {
        if (line.empty()) {
            if (!current_group.empty()) {
                grouped_numbers.push_back(current_group);
                current_group = {};
            }
        } else {
            current_group.push_back(std::stoi(line));
        }
    }

    if (!current_group.empty())
        grouped_numbers.push_back(current_group);

    return grouped_numbers;
}
