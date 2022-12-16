#include <iterator>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <array>
#include <numeric>

int day3() {
    std::unordered_map<char, int> priorities = {
        {'a', 1},
        {'b', 2},
        {'c', 3},
        {'d', 4},
        {'e', 5},
        {'f', 6},
        {'g', 7},
        {'h', 8},
        {'i', 9},
        {'j', 10},
        {'k', 11},
        {'l', 12},
        {'m', 13},
        {'n', 14},
        {'o', 15},
        {'p', 16},
        {'q', 17},
        {'r', 18},
        {'s', 19},
        {'t', 20},
        {'u', 21},
        {'v', 22},
        {'w', 23},
        {'x', 24},
        {'y', 25},
        {'z', 26},
        {'A', 27},
        {'B', 28},
        {'C', 29},
        {'D', 30},
        {'E', 31},
        {'F', 32},
        {'G', 33},
        {'H', 34},
        {'I', 35},
        {'J', 36},
        {'K', 37},
        {'L', 38},
        {'M', 39},
        {'N', 40},
        {'O', 41},
        {'P', 42},
        {'Q', 43},
        {'R', 44},
        {'S', 45},
        {'T', 46},
        {'U', 47},
        {'V', 48},
        {'W', 49},
        {'X', 50},
        {'Y', 51},
        {'Z', 52}
    };

    std::fstream input_file;
    input_file.open("../input_files/day3_input.txt", std::ios::in);
    if (!input_file.is_open()) {
        return -1;
    }
    using Set = std::vector<char>;
    using RuckGroup = std::tuple<Set, Set, Set>;
    std::vector<RuckGroup> rucks;
    std::array<Set, 3> group;
    int count = 0;
    for (std::string line; std::getline(input_file, line); ) {
        Set sack(line.begin(), line.end());
        group[count] = sack;
        ++count;
        if (count == 3) {
            rucks.emplace_back(std::move(group[0]), std::move(group[1]), std::move(group[2]));
            count = 0;
        }
    }
    std::vector<int> results;
    std::transform(rucks.begin(), rucks.end(), std::back_inserter(results), [&priorities](RuckGroup &group) {
        std::vector<char> intersection;
        std::vector<char> result;
        auto const &first = std::get<0>(group);
        auto const &second = std::get<1>(group);
        auto const &third = std::get<2>(group);
        std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(intersection));
        std::set_intersection(intersection.begin(), intersection.end(), third.begin(), third.end(), std::back_inserter(result));
        return priorities[*intersection.begin()];
    });

    return std::accumulate(results.begin(), results.end(), 0);
}