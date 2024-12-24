#include <bits/stdc++.h>
using namespace std;

long long part2(const vector<string>& data) {
    string pattern = R"((mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\)))";
    regex re(pattern);
    smatch match;

    bool enabled = true;
    long long result = 0;

    for (const string& line : data) {
        string line_copy = line;
        while (regex_search(line_copy, match, re)) {
            if (match[0] == "do()") {
                enabled = true;
            } else if (match[0] == "don't()") {
                enabled = false;
            } else if (enabled) {
                result += stoll(match[2]) * stoll(match[3]);
            }
            line_copy = match.suffix();
        }
    }

    return result;
}

int main() {
    ifstream input_file("input.txt");
    vector<string> data;
    string line;

    while (getline(input_file, line)) {
        data.push_back(line);
    }

    input_file.close();
    cout << part2(data) << endl;

    return 0;
}
