#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    string line;
    int total_tokens = 0;
    [[maybe_unused]] int solvable = 0;

    while (getline(infile, line)) {
        if (line.empty())
            continue;

        regex pattern("X\\+(\\d+), Y\\+(\\d+)");
        smatch matches;
        regex_search(line, matches, pattern);
        int a_x = stoi(matches[1]);
        int a_y = stoi(matches[2]);

        getline(infile, line);
        regex_search(line, matches, pattern);
        int b_x = stoi(matches[1]);
        int b_y = stoi(matches[2]);

        getline(infile, line);
        regex pattern2("X=(\\d+), Y=(\\d+)");
        regex_search(line, matches, pattern2);
        int prize_x = stoi(matches[1]);
        int prize_y = stoi(matches[2]);

        bool found = false;
        for (int a = 0; a <= 100 && !found; a++) {
            for (int b = 0; b <= 100; b++) {
                if (a * a_x + b * b_x == prize_x && a * a_y + b * b_y == prize_y) {
                    total_tokens += 3 * a + b;
                    solvable++;
                    found = true;
                    break;
                }
            }
        }
    }

    outfile << total_tokens << '\n';

    infile.close();
    outfile.close();

    return 0;
}
