#pragma once

#if _WIN32 || _WIN64
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <optional>
#include <string>

struct TempFile {
    TempFile() : name(std::tmpnam(nullptr))
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

std::optional<std::string> find_input_file(const std::string& day);
