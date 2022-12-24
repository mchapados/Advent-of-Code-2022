#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>

struct Position {
    int r; // row
    int c; // column
    bool operator == (Position const &obj) const {
        if (r == obj.r && c == obj.c)
            return true;
        return false;
    };
    bool operator != (Position const &obj) const {
        if (r != obj.r || c != obj.c)
            return true;
        return false;
    };
    bool operator < (Position const &obj) const {
        if (r < obj.r)
            return true;
        else if (r == obj.r && c < obj.c)
            return true;
        return false;
    };
    bool operator > (Position const &obj) const {
        if (r > obj.r)
            return true;
        else if (r == obj.r && c > obj.c)
            return true;
        return false;
    };
};

class Heightmap {
    public:
        Position start, end;
        Heightmap(std::string filepath) {
            // open input file
            std::fstream input_file;
            input_file.open("../input_files/day12_input.txt", std::ios::in);
            if (!input_file.is_open()) {
                return;
            }

            // create the heightmap from file
            for (std::string line; std::getline(input_file, line); ) {
                map.emplace_back(std::vector<char>(line.begin(), line.end()));
            }
            input_file.close();

            // find start and end positions
            for (int i = 0; i < map.size(); ++i) {
                for (int j = 0; j < map[i].size(); ++j) {
                    if (map[i][j] == 'S') {
                        start = {i, j};
                        map[i][j] = 'a';
                    }
                    else if (map[i][j] == 'E') {
                        end = {i, j};
                        map[i][j] = 'z';
                    }
                }
            }
        } // end constructor

        int shortest_path() {
            std::deque<std::vector<Position>> q;
            std::set<Position> visited;
            q.emplace_back(std::vector<Position>());
            q[0].emplace_back(start);
            std::vector<Position> path, path_copy;
            Position curr;
            int height;
            while (!q.empty()) {
                path = q.back();
                q.pop_back();
                curr = path[path.size()-1];
                if (!visited.contains(curr)) {
                    visited.insert(curr);
                    if (curr == end) {
                        return path.size()-1;
                    }
                    height = map[curr.r][curr.c];
                    // check left path
                    if (curr.c > 0 && (map[curr.r][curr.c-1] <= height + 1)) {
                        path_copy = path;
                        path_copy.push_back({curr.r, curr.c-1});
                        q.emplace_front(path_copy);
                    }
                    // check right path
                    if (curr.c < map[0].size()-1 && (map[curr.r][curr.c+1] <= height + 1)) {
                        path_copy = path;
                        path_copy.push_back({curr.r, curr.c+1});
                        q.emplace_front(path_copy);
                    }
                    // check up path
                    if (curr.r > 0 && (map[curr.r-1][curr.c] <= height + 1)) {
                        path_copy = path;
                        path_copy.push_back({curr.r-1, curr.c});
                        q.emplace_front(path_copy);
                    }
                    // check down path
                    if (curr.r < map.size()-1 && (map[curr.r+1][curr.c] <= height + 1)) {
                        path_copy = path;
                        path_copy.push_back({curr.r+1, curr.c});
                        q.emplace_front(path_copy);
                    }
                }
            }
            return 2147483647; // no possible path
        }
    private:
        std::vector<std::vector<char>> map;
};

int day12() {
    Heightmap heightmap("../input_files/day12_input.txt");  
    return heightmap.shortest_path();
}