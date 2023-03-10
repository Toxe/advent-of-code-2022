#include "test_helpers.hpp"

#include <random>

#include "read_input.hpp"

std::optional<std::string> find_input_file(const std::string& day)
{
    const std::vector<std::string> filenames = {
        "input.txt",
        "src/" + day + "/input.txt",
        "../../../src/" + day + "/input.txt",
        "../../../../src/" + day + "/input.txt",
        "../../../../../src/" + day + "/input.txt",
    };

    for (const auto& file : filenames)
        if (file_exists(file))
            return file;

    return {};
}

std::string generate_temp_file_name()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(100000, 999999);

    const auto temp_dir_path = std::filesystem::temp_directory_path();
    std::string name;

    while (true) {
        auto tmp = temp_dir_path / ("aoc_tmp_" + std::to_string(dist(gen)));

        if (!std::filesystem::exists(tmp)) {
            name = tmp.string();
            break;
        }
    }

    return name;
}
