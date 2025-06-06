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

    int n;
    cin >> n;
    vector<int> a(n);
    int m{};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m += a[i];
    }

    map<int, vector<int>> mp;
    int x{}, y{};
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < a[i]; j++) {
          mp[x].push_back(y);
          x -= 1;
          y += 1;
        }
        x += 1;
      } else {
        for (int j = 0; j < a[i]; j++) {
          mp[x].push_back(-y);
          x += 1;
          y += 1;
        }
        x -= 1;
      }
    }
    vector<string> res;
    for (const auto &v: mp | views::values) {
      string tmp{};
      for (int i = 0; i < m; i++) {
        tmp += " ";
      }
      for (const auto idx: v) {
        if (idx >= 0) {
          tmp[idx] = '/';
        } else {
          tmp[-idx] = '\\';
        }
      }
      res.push_back(tmp);
    }
    for (const auto &s: res) {
      cout << s << '\n';
    }
  }
