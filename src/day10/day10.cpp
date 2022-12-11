#include "day10.hpp"

#include <cassert>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>

struct Instruction {
    enum class Opcode {
        noop,
        addx
    };

    Opcode opcode;
    int cycles;
    int value;
};

struct CPU {
    int cycle = 0;
    int x = 1;
    Instruction instruction{Instruction::Opcode::noop, 0, 0};
};

bool has_hit_sprite(const CPU& cpu, const int crt)
{
    return (crt >= cpu.x - 1) && (crt <= cpu.x + 1);
}

void execute_instruction(CPU& cpu)
{
    assert(cpu.instruction.cycles > 0);

    --cpu.instruction.cycles;

    switch (cpu.instruction.opcode) {
        case Instruction::Opcode::noop: break;
        case Instruction::Opcode::addx:
            if (cpu.instruction.cycles == 0)
                cpu.x += cpu.instruction.value;
            break;
    }
}

void read_next_instruction(CPU& cpu, const std::string& line)
{
    if (line.starts_with("noop"))
        cpu.instruction = Instruction{Instruction::Opcode::noop, 1, 0};
    else if (line.starts_with("addx"))
        cpu.instruction = Instruction{Instruction::Opcode::addx, 2, std::stoi(line.substr(5))};
    else
        throw std::runtime_error{"invalid instruction"};
}

void next_cycle(CPU& cpu, std::vector<std::string>::const_iterator& instruction_pointer)
{
    if (cpu.instruction.cycles == 0) {
        read_next_instruction(cpu, *instruction_pointer);
        ++instruction_pointer;
    }

    ++cpu.cycle;
}

using Widget = std::function<void(const CPU& cpu)>;

void run(const std::vector<std::string>& lines, const Widget& run_widget)
{
    CPU cpu;
    auto instruction_pointer = lines.begin();

    while (instruction_pointer != lines.end()) {
        next_cycle(cpu, instruction_pointer);
        run_widget(cpu);
        execute_instruction(cpu);
    }
}

int day10_part1(const std::vector<std::string>& lines)
{
    int signal_strength = 0;
    const auto widget = [&](const CPU& cpu) {
        if (cpu.cycle == 20 || ((cpu.cycle + 20) % 40 == 0))
            signal_strength += cpu.cycle * cpu.x;
    };

    run(lines, widget);

    return signal_strength;
}

std::string day10_part2(const std::vector<std::string>& lines)
{
    int crt = 0;
    std::stringstream buffer;
    const auto widget = [&](const CPU& cpu) {
        buffer << (has_hit_sprite(cpu, crt) ? '#' : '.');

        if (++crt % 40 == 0) {
            buffer << '\n';
            crt = 0;
        }
    };

    run(lines, widget);

    return buffer.str();
}
