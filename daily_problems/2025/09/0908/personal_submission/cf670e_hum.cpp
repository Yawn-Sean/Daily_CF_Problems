#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, p;
  cin >> n >> m >> p;

  string s;
  cin >> s;

  vector<int> s1, s2;

  for (auto &c: s) {
    if (c == '(') s1.emplace_back(1);
    else s1.emplace_back(-1);
  }

  while (s1.size() > p) {
    int x = s1.back();
    s1.pop_back();
    s2.emplace_back(x);
  }

  cin >> s;

  for (auto &c: s) {
    if (c == 'R') {
      int x = s2.back();
      s2.pop_back();
      s1.emplace_back(x);
    } else if (c == 'L') {
      int x = s1.back();
      s1.pop_back();
      s2.emplace_back(x);
    } else {
      int x = s1.back();
      s1.pop_back();
      if (x == 1) {
        while (x) {
          x += s2.back();
          s2.pop_back();
        }
      } else {
        while (x) {
          x += s1.back();
          s1.pop_back();
        }
      }

      if (s2.size()) {
        x = s2.back();
        s2.pop_back();
        s1.emplace_back(x);
      }
    }
  }

  while (!s2.empty()) {
    s1.emplace_back(s2.back());
    s2.pop_back();
  }

  for (auto &c: s1) cout << (c == 1 ? '(' : ')');
}
