#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main() {
    vector<int> left_list;
    vector<int> right_list;
    int number;

    while (in >> number) {
        left_list.push_back(number);
        if (in >> number) {
            right_list.push_back(number);
        }
    }

    in.close();

    unordered_map<int, int> frequency_map;

    for (int num : right_list) {
        frequency_map[num]++;
    }

    int total_similarity_score = 0;

    for (int num : left_list) {
        total_similarity_score += num * frequency_map[num];
    }

    out << total_similarity_score << endl;

    out.close();

    return 0;
}
