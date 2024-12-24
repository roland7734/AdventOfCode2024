#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  long long sum = 0;

  while (getline(cin, s)) {
    for (int i = 0; i < (int)s.size() - 3; i++) {
      if (s[i] == 'm' && s[i + 1] == 'u' && s[i + 2] == 'l' &&
          s[i + 3] == '(') {
        int j = i + 4;
        string x, y;

        while (j < (int)s.size() && isdigit(s[j])) {
          x += s[j++];
        }

        if (j >= (int)s.size() || s[j] != ',' || x.size() > 3)
          continue;
        j++;

        while (j < (int)s.size() && isdigit(s[j])) {
          y += s[j++];
        }

        if (j >= (int)s.size() || s[j] != ')' || y.size() > 3)
          continue;

        if (!x.empty() && !y.empty()) {
          long long num1 = stoll(x);
          long long num2 = stoll(y);
          if (num1 <= 999 && num2 <= 999) {
            sum += num1 * num2;
          }
        }
      }
    }
  }

  cout << sum << endl;
}

int main() {
  solve();
  return 0;
}
