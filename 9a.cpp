#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ifstream in("input.txt");
  ofstream out("output.txt");

  string s;
  in >> s;

  vector<int> blocks;
  int fileId = 0;

  for (size_t i = 0; i < s.length(); i++) {
    int len = s[i] - '0';
    if (i % 2 == 0) {
      for (int j = 0; j < len; j++) {
        blocks.push_back(fileId);
      }
      fileId++;
    } else {
      for (int j = 0; j < len; j++) {
        blocks.push_back(-1);
      }
    }
  }

  while (true) {
    int right = blocks.size() - 1;
    while (right >= 0 && blocks[right] == -1) {
      right--;
    }
    if (right < 0)
      break;

    int left = 0;
    while (static_cast<size_t>(left) < blocks.size() && blocks[left] != -1) {
      left++;
    }
    if (left >= right)
      break;

    blocks[left] = blocks[right];
    blocks[right] = -1;
  }

  long long checksum = 0;
  for (size_t i = 0; i < blocks.size(); i++) {
    if (blocks[i] != -1) {
      checksum += (long long)i * blocks[i];
    }
  }

  out << checksum << '\n';

  in.close();
  out.close();

  return 0;
}
