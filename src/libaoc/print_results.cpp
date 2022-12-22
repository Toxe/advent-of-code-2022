#include "print_results.hpp"

#include "fmt/core.h"

template <typename T>
void print(const int day, const int part, const T& result)
{
    fmt::print("day {:02}, part {}: {}\n", day, part, result);
}

void print_result(const int day, int part, const int result)
{
    print(day, part, result);
}

void print_result(const int day, int part, const std::string& result)
{
    print(day, part, result);
}
