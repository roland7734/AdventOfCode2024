#include <bits/stdc++.h>
using namespace std;

int64_t computeGCD(int64_t x, int64_t y) {
    while (y) {
        int64_t temp = y;
        y = x % y;
        x = temp;
    }
    return abs(x);
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string line;
    int64_t tokenSum = 0;
    const int64_t SHIFT = 10000000000000LL;

    while (getline(input, line)) {
        if (line.empty())
            continue;

        regex pattern("X\\+(\\d+), Y\\+(\\d+)");
        smatch matches;
        regex_search(line, matches, pattern);
        int64_t x1 = stoll(matches[1]);
        int64_t y1 = stoll(matches[2]);

        getline(input, line);
        regex_search(line, matches, pattern);
        int64_t x2 = stoll(matches[1]);
        int64_t y2 = stoll(matches[2]);

        getline(input, line);
        regex pattern2("X=(\\d+), Y=(\\d+)");
        regex_search(line, matches, pattern2);
        int64_t targetX = stoll(matches[1]) + SHIFT;
        int64_t targetY = stoll(matches[2]) + SHIFT;

        int64_t determinant = x1 * y2 - y1 * x2;
        if (determinant == 0)
            continue;

        long double p = (targetX * (long double)y2 - targetY * (long double)x2) / determinant;
        long double q = (x1 * (long double)targetY - y1 * (long double)targetX) / determinant;

        if (p >= 0 && q >= 0 && abs(p - roundl(p)) < 1e-10 && abs(q - roundl(q)) < 1e-10) {
            int64_t pInt = roundl(p);
            int64_t qInt = roundl(q);
            tokenSum += 3 * pInt + qInt;
        }
    }

    output << tokenSum << '\n';

    input.close();
    output.close();

    return 0;
}
