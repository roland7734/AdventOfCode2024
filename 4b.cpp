#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int countXMAS(const vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    for (int r = 1; r < n - 1; ++r) {
        for (int c = 1; c < m - 1; ++c) {
            if (grid[r][c] == 'A') {
                if (grid[r - 1][c - 1] == 'M' && grid[r + 1][c + 1] == 'S' &&
                    grid[r - 1][c + 1] == 'S' && grid[r + 1][c - 1] == 'M') {
                    count++;
                }
                if (grid[r - 1][c + 1] == 'S' && grid[r + 1][c - 1] == 'M' &&
                    grid[r - 1][c - 1] == 'M' && grid[r + 1][c + 1] == 'S') {
                    count++;
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
