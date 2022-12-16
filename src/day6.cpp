#include <cstddef>
#include <fstream>
#include <set>

int day6(int distinct_chars) {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day6_input.txt", std::ios::in);
    // if file failed to open, return 
    if (!input_file.is_open()) {
        return -1;
    }
    std::string datastream, temp;
    std::getline(input_file, datastream);
    std::set<char> marker;
    int result = 0;
    for (size_t i = distinct_chars-1; i < datastream.size(); ++i) {
        temp = datastream.substr(i-distinct_chars+1, distinct_chars);
        marker = std::set<char>(temp.begin(), temp.end());
        if (marker.size() == distinct_chars) {
            result = i + 1;
            break;
        }
    }
    return result;
}