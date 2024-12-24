#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int countXMAS(const vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    string word = "XMAS";
    int count = 0;

    vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    auto isValid = [&](int r, int c, int dr, int dc) {
        for (int i = 0; i < 4; ++i) {
            int nr = r + i * dr;
            int nc = c + i * dc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] != word[i]) {
                return false;
            }
        }
        return true;
    };

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == 'X') {
                for (auto& dir : directions) {
                    int dr = dir.first;
                    int dc = dir.second;
                    if (isValid(r, c, dr, dc)) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    vector<string> grid;
    string line;

    while (getline(inFile, line)) {
        grid.push_back(line);
    }

    int result = countXMAS(grid);
    outFile << result << endl;

    inFile.close();
    outFile.close();

    return 0;
}
