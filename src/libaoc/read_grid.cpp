#include "read_grid.hpp"

#include <stdexcept>
#include <string>

ByteGrid read_digit_grid(std::istream& input)
{
    std::vector<std::vector<ByteGrid::value_type>> data;
    std::string line;

    while (std::getline(input, line)) {
        if (line.empty())
            break;

        std::vector<ByteGrid::value_type> values;

        for (const char c : line) {
            if (c < '0' || c > '9')
                throw std::runtime_error{"invalid input"};

            values.push_back(static_cast<ByteGrid::value_type>(c - '0'));
        }

        if (!data.empty() && values.size() != data.front().size())
            throw std::runtime_error{"column size mismatch"};

        data.push_back(values);
    }

    ByteGrid grid{static_cast<int>(data.size()), static_cast<int>(data[0].size())};

    for (std::size_t row = 0; row < data.size(); ++row)
        for (std::size_t col = 0; col < data[row].size(); ++col)
            grid.value(static_cast<int>(row), static_cast<int>(col)) = data[row][col];

    return grid;
}
