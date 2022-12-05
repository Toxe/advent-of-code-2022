#include "day05.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <tuple>

struct Instruction {
    int num_crates;
    std::size_t from;
    std::size_t to;
};

using Crate = char;
using CrateStack = std::stack<Crate>;
using CrateMover = std::function<void(Instruction, std::vector<CrateStack>&)>;

std::tuple<std::vector<std::string>, std::vector<std::string>> split_input_into_stack_and_instructions(const std::vector<std::string>& lines)
{
    std::vector<std::string> initial_crate_stack_input;
    std::vector<std::string> instructions_input;

    const auto empty_line = std::find(lines.begin(), lines.end(), "");

    initial_crate_stack_input.resize(static_cast<std::size_t>(std::distance(lines.begin(), empty_line)));
    instructions_input.resize(static_cast<std::size_t>(std::distance(std::next(empty_line), lines.end())));

    std::copy(lines.begin(), empty_line, initial_crate_stack_input.begin());
    std::copy(std::next(empty_line), lines.end(), instructions_input.begin());

    return {initial_crate_stack_input, instructions_input};
}

std::size_t find_number_of_stacks(const std::string& line)
{
    std::istringstream in{line};
    std::size_t number_of_stacks = 0;

    while (in)
        in >> number_of_stacks;

    return number_of_stacks;
}

std::vector<Crate> parse_crate_stack_line(const std::string& line, const std::size_t number_of_stacks)
{
    // expand input line to full width so that it can hold all stack markers
    std::string expanded_line(3 * number_of_stacks + (number_of_stacks - 1), ' ');
    std::copy(line.begin(), line.end(), expanded_line.begin());

    // the crates from this input line (either alphabetic characters or ' ')
    std::vector<Crate> crates(number_of_stacks, ' ');

    for (std::size_t stack_nr = 0; stack_nr < number_of_stacks; ++stack_nr)
        crates[stack_nr] = expanded_line[1 + stack_nr * 4];

    return crates;
}

std::vector<CrateStack> read_initial_crate_stacks(const std::vector<std::string>& input)
{
    const std::size_t number_of_stacks = find_number_of_stacks(input.back());

    // create empty crate stacks
    std::vector<CrateStack> crate_stacks(number_of_stacks);

    // parse stack lines in reverse order
    std::for_each(std::next(input.rbegin()), input.rend(), [&](const std::string& line) {
        auto stack_iter = crate_stacks.begin();

        // push crates onto their stacks
        for (const Crate crate : parse_crate_stack_line(line, number_of_stacks)) {
            if (crate != ' ')
                stack_iter->push(crate);

            ++stack_iter;
        }
    });

    return crate_stacks;
}

Instruction parse_instruction_line(const std::string& line)
{
    Instruction instruction{};
    std::string skip;

    std::istringstream{line} >> skip >> instruction.num_crates >> skip >> instruction.from >> skip >> instruction.to;

    return instruction;
}

std::vector<Instruction> read_instructions(const std::vector<std::string>& input)
{
    std::vector<Instruction> instructions;

    for (const auto& line : input)
        instructions.push_back(parse_instruction_line(line));

    return instructions;
}

Crate pop_top(CrateStack& crate_stack)
{
    const Crate crate = crate_stack.top();
    crate_stack.pop();
    return crate;
}

void crate_mover_9000(Instruction instruction, std::vector<CrateStack>& crate_stacks)
{
    while (instruction.num_crates-- > 0)
        crate_stacks[instruction.to - 1].push(pop_top(crate_stacks[instruction.from - 1]));
}

void crate_mover_9001(Instruction instruction, std::vector<CrateStack>& crate_stacks)
{
    CrateStack buffer;

    while (instruction.num_crates-- > 0)
        buffer.push(pop_top(crate_stacks[instruction.from - 1]));

    while (!buffer.empty())
        crate_stacks[instruction.to - 1].push(pop_top(buffer));
}

std::string do_it(const std::vector<std::string>& lines, const CrateMover& crate_mover)
{
    const auto [initial_crate_stack_input, instructions_input] = split_input_into_stack_and_instructions(lines);
    auto crate_stacks = read_initial_crate_stacks(initial_crate_stack_input);
    const std::vector<Instruction> instructions = read_instructions(instructions_input);

    for (const auto& instruction : instructions)
        crate_mover(instruction, crate_stacks);

    std::string answer;

    for (auto& stack : crate_stacks)
        answer += stack.top();

    return answer;
}

std::string day05_part1(const std::vector<std::string>& lines)
{
    return do_it(lines, crate_mover_9000);
}

std::string day05_part2(const std::vector<std::string>& lines)
{
    return do_it(lines, crate_mover_9001);
}
