#include "test_helpers.hpp"

#include "read_input.hpp"

std::optional<std::string> find_input_file(const std::string& day)
{
    const std::vector<std::string> filenames = {
        "input.txt",
        "src/" + day + "/input.txt",
        "../../../src/" + day + "/input.txt",
    };

    for (const auto& file : filenames)
        if (file_exists(file))
            return file;

    return {};
}
