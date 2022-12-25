#pragma once

#include <filesystem>
#include <fstream>
#include <optional>
#include <string>

std::optional<std::string> find_input_file(const std::string& day);
std::string generate_temp_file_name();

struct TempFile {
    TempFile() : name(generate_temp_file_name())
    {
        file = std::ofstream{name, std::ios::binary};
    }

    ~TempFile()
    {
        if (file.is_open()) {
            file.close();
            std::filesystem::remove(name);
        }
    }

    std::string name;
    std::ofstream file;
};
