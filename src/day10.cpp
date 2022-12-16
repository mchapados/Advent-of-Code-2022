#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <array>


int day10() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day10_input.txt", std::ios::in);
    // if file failed to open, return 
    if (!input_file.is_open()) {
        return -1;
    }

    int cycle = 0;
    int result = 0;
    int x = 1;
    int next = 20;
    for (std::string line; std::getline(input_file, line); ) {
        ++cycle;
        if (cycle == next) {
            next += 40;
            result += cycle * x;
        }
        if (line.substr(0, 4) == "addx") {
            ++cycle;
            if (cycle == next) {
                next += 40;
                result += cycle * x;
            }
            x += std::stoi(line.substr(line.find(' ')+1));
        }
    }

    return result;
}

char draw_pixel(int cycle, int x) {
    cycle = (cycle % 40) - 1;
    if (cycle <= x+1 && cycle >= x-1)
        return '#';
    return '.';
}

std::string day10_pt2() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day10_input.txt", std::ios::in);
    // if file failed to open, return 
    if (!input_file.is_open()) {
        return "";
    }

    std::string screen = "";
    int cycle = 0;
    int x = 1;

    for (std::string line; std::getline(input_file, line); ) {
        ++cycle;
        screen += draw_pixel(cycle, x);
        if (cycle % 40 == 0)
            screen += '\n';
        if (line.substr(0, 4) == "addx") {
            ++cycle;
            screen += draw_pixel(cycle, x);
            if (cycle % 40 == 0)
                screen += '\n';
            x += std::stoi(line.substr(line.find(' ')+1));
        }
    }

    return screen;
}