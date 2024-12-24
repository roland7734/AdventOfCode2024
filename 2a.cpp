#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

bool isSafeReport(const vector<int>& levels) {
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = abs(levels[i] - levels[i - 1]);

        if (diff < 1 || diff > 3) {
            return false;
        }

        if (levels[i] < levels[i - 1]) {
            isIncreasing = false;
        }

        if (levels[i] > levels[i - 1]) {
            isDecreasing = false;
        }
    }

    return isIncreasing || isDecreasing;
}

int main() {
    int safeReportCount = 0;
    string line;

    while (getline(in, line)) {
        vector<int> levels;
        int number;
        stringstream ss(line);

        while (ss >> number) {
            levels.push_back(number);
        }

        if (isSafeReport(levels)) {
            safeReportCount++;
        }
    }

    out << safeReportCount << endl;
    out.close();
    in.close();

    return 0;
}
