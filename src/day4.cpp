#include <fstream>
#include <string>
#include <tuple>

// In how many assignment pairs does one range fully contain the other?
int day4() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day4_input.txt", std::ios::in);
    // if file failed to open, return -1
    if (!input_file.is_open()) {
        return -1;
    }
    // iterate through input file
    int result = 0;
    for (std::string line; std::getline(input_file, line); ) {
        std::string elf1 = line.substr(0, line.find(','));
        std::string elf2 = line.substr(line.find(',')+1);
        std::tuple<int, int> elf1_sections = std::make_tuple(std::stoi(elf1.substr(0, elf1.find('-'))), std::stoi(elf1.substr(elf1.find('-')+1)));
        std::tuple<int, int> elf2_sections = std::make_tuple(std::stoi(elf2.substr(0, elf2.find('-'))), std::stoi(elf2.substr(elf2.find('-')+1)));
        // check if elf1 is contained in elf2
        if (std::get<0>(elf1_sections) >= std::get<0>(elf2_sections) && std::get<1>(elf1_sections) <= std::get<1>(elf2_sections))
            ++result;
        // check if elf2 is contained in elf1
        else if (std::get<0>(elf2_sections) >= std::get<0>(elf1_sections) && std::get<1>(elf2_sections) <= std::get<1>(elf1_sections))
            ++result;
    }
    input_file.close();
    return result;
}

// In how many assignment pairs do the ranges overlap?
int day4_pt2() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day4_input.txt", std::ios::in);
    // if file failed to open, return -1
    if (!input_file.is_open()) {
        return -1;
    }
    // iterate through input file
    int result = 0;
    for (std::string line; std::getline(input_file, line); ) {
        std::string elf1 = line.substr(0, line.find(','));
        std::string elf2 = line.substr(line.find(',')+1);
        std::tuple<int, int> elf1_sections = std::make_tuple(std::stoi(elf1.substr(0, elf1.find('-'))), std::stoi(elf1.substr(elf1.find('-')+1)));
        std::tuple<int, int> elf2_sections = std::make_tuple(std::stoi(elf2.substr(0, elf2.find('-'))), std::stoi(elf2.substr(elf2.find('-')+1)));
        // check if elf1 start is in elf2
        if (std::get<0>(elf1_sections) >= std::get<0>(elf2_sections) && std::get<0>(elf1_sections) <= std::get<1>(elf2_sections))
            ++result;
        // check if elf1 end is in elf2
        else if (std::get<1>(elf1_sections) >= std::get<0>(elf2_sections) && std::get<1>(elf1_sections) <= std::get<1>(elf2_sections))
            ++result;
        else if (std::get<0>(elf2_sections) >= std::get<0>(elf1_sections) && std::get<0>(elf2_sections) <= std::get<1>(elf1_sections))
            ++result;
        else if (std::get<1>(elf2_sections) >= std::get<0>(elf1_sections) && std::get<1>(elf2_sections) <= std::get<1>(elf1_sections))
            ++result;
    }
    input_file.close();
    return result;
}