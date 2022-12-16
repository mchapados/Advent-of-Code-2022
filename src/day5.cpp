#include <algorithm>
#include <cstddef>
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <iostream>

std::string day5() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day5_input.txt", std::ios::in);
    // if file failed to open, return empty string
    if (!input_file.is_open()) {
        return "";
    }

    std::vector<std::deque<char>> crate_stacks; // vector of crate stacks
    bool first_line = true;
    int move_num, from, to;

    for (std::string line; std::getline(input_file, line); ) {
        // create the crate stacks
        if (line.find('[') != std::string::npos) {
            size_t j = 0; // stack index in vector
            // iterate through each crate in the line
            for (size_t i = 1; i < line.size(); i += 4) {
                if (first_line) // if first line, create a new stack
                    crate_stacks.emplace_back(std::deque<char>());
                if (line[i] != ' ') // if this slot is not empty, insert onto bottom of stack
                    crate_stacks[j].emplace_back(line[i]);
                ++j; // go to next stack
            }
        }
        // move the crates
        else if (line.find('m') != std::string::npos) {
            // extract the integer values
            move_num = stoi(line.substr(5, line.find('f')-6));
            from = stoi(line.substr(line.find('f')+5, line.find('t')-line.find('f')-6)) - 1;
            to = stoi(line.substr(line.find('t')+3)) - 1;
            // move each crate
            for (int i = 0; i < move_num; ++i) {
                crate_stacks[to].push_front(crate_stacks[from].front());
                crate_stacks[from].pop_front();
            }
        }
        first_line = false;
    }
    input_file.close();
    // figure out which crate is the top of each stack
    std::string result = "";
    for (auto stack : crate_stacks) {
        result += stack.front();
    }
    return result;
}

std::string day5_pt2() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day5_input.txt", std::ios::in);
    // if file failed to open, return empty string
    if (!input_file.is_open()) {
        return "";
    }

    std::vector<std::deque<char>> crate_stacks; // vector of crate stacks
    bool first_line = true;
    int move_num, from, to;

    for (std::string line; std::getline(input_file, line); ) {
        // create the crate stacks
        if (line.find('[') != std::string::npos) {
            size_t j = 0; // stack index in vector
            // iterate through each crate in the line
            for (size_t i = 1; i < line.size(); i += 4) {
                if (first_line) // if first line, create a new stack
                    crate_stacks.emplace_back(std::deque<char>());
                if (line[i] != ' ') // if this slot is not empty, insert onto bottom of stack
                    crate_stacks[j].emplace_back(line[i]);
                ++j; // go to next stack
            }
        }
        // move the crates
        else if (line.find('m') != std::string::npos) {
            // extract the integer values
            move_num = stoi(line.substr(5, line.find('f')-6));
            from = stoi(line.substr(line.find('f')+5, line.find('t')-line.find('f')-6)) - 1;
            to = stoi(line.substr(line.find('t')+3)) - 1;
            // move each crate
            for (int i = move_num-1; i >= 0; --i) {
                crate_stacks[to].push_front(crate_stacks[from][i]);
                crate_stacks[from].erase(crate_stacks[from].begin()+i);
            }
        }
        first_line = false;
    }
    input_file.close();
    // figure out which crate is the top of each stack
    std::string result = "";
    for (auto stack : crate_stacks) {
        result += stack.front();
    }
    return result;
}