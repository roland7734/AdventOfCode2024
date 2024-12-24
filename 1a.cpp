#include <iostream>
#include <vector>
#include <algorithm>
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

    sort(left_list.begin(), left_list.end());
    sort(right_list.begin(), right_list.end());

    int total_distance = 0;
    for (int i = 0; i < left_list.size(); ++i) {
        total_distance += abs(left_list[i] - right_list[i]);
    }

    out << total_distance << endl;

    out.close();

    return 0;
}
