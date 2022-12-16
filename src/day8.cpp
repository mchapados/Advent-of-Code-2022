#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include <array>

// how many trees are visible from outside the grid?
int day8() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day8_input.txt", std::ios::in);
    // if file failed to open, return 
    if (!input_file.is_open()) {
        return -1;
    }

    int result = 0;

    // create the 2d array of trees
    std::vector<std::vector<int>> trees;
    for (std::string line; std::getline(input_file, line); ) {
        std::vector<int> row;
        for (auto c : line) {
            row.push_back(c-48);
        }
        trees.push_back(row);
    }

    // for each tree
  std::array<bool, 4> visible;
    for (int i = 0; i < trees.size(); ++i) {
        for (int j = 0; j < trees[i].size(); ++j) {
            visible = {true, true, true, true};
            // check if it's on the border
            if (i == 0 || i == trees.size()-1 || j == 0 || j == trees[i].size()-1) {
            }
            else {
                // check above
                for (int k = 1; i-k >= 0; ++k) {
                    if (trees[i-k][j] >= trees[i][j]) {
                        visible[0] = false; // not visible in this direction
                        break;
                    }
                }
                // check below
                for (int k = 1; i+k < trees.size(); ++k) {
                    if (trees[i+k][j] >= trees[i][j]) {
                        visible[1] = false; // not visible in this direction
                        break;
                    }
                }
                // check right
                for (int k = 1; j+k < trees[i].size(); ++k) {
                    if (trees[i][j+k] >= trees[i][j]) {
                        visible[2] = false; // not visible in this direction
                        break;
                    }
                }
                // check left
                for (int k = 1; j-k >= 0; ++k) {
                    if (trees[i][j-k] >= trees[i][j]) {
                        visible[3] = false; // not visible in this direction
                        break;
                    }
                }
            }
            // if visible in any direction, it is visible
            for (auto dir : visible) {
                if (dir == true) {
                    ++result;
                    break;
                }
            }
        }
    }
    return result;
}

// What is the highest scenic score possible for any tree?
int day8_pt2() {
    // open input file
    std::fstream input_file;
    input_file.open("../input_files/day8_input.txt", std::ios::in);
    // if file failed to open, return 
    if (!input_file.is_open()) {
        return -1;
    }



    // create the 2d array of trees
    std::vector<std::vector<int>> trees;
    for (std::string line; std::getline(input_file, line); ) {
        std::vector<int> row;
        for (auto c : line) {
            row.push_back(c-48);
        }
        trees.push_back(row);
    }

    // for each tree
    int high_score = 0;
    int curr_score;
    std::array<int, 4> visible_trees;
    for (int i = 0; i < trees.size(); ++i) {
        for (int j = 0; j < trees[i].size(); ++j) {
            visible_trees = {0, 0, 0, 0};
            // check above
            for (int k = 1; i-k >= 0; ++k) {
                ++visible_trees[0];
                if (trees[i-k][j] >= trees[i][j]) { 
                    break;
                }
            }
            // check below
            for (int k = 1; i+k < trees.size(); ++k) {
                ++visible_trees[1];
                if (trees[i+k][j] >= trees[i][j]) {
                    break;
                }
            }
            // check right
            for (int k = 1; j+k < trees[i].size(); ++k) {
                ++visible_trees[2];
                if (trees[i][j+k] >= trees[i][j]) {
                    break;
                }
            }
            // check left
            for (int k = 1; j-k >= 0; ++k) {
                ++visible_trees[3];
                if (trees[i][j-k] >= trees[i][j]) {
                    break;
                }
            }
            curr_score = visible_trees[0] * visible_trees[1] * visible_trees[2] * visible_trees[3];
            if (high_score < curr_score) {
                high_score = curr_score;
            }
        }
    }
    return high_score;
}