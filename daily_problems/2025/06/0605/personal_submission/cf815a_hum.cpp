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

  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector<pair<string, int>> res;
  function<bool(int)> row = [&](int i) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        return false;
      }
    }
    for (int j = 0; j < m; j++) {
      a[i][j]--;
    }
    res.push_back({"row", i + 1});
    return true;
  };

  function<bool(int)> col = [&](int i) {
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 0) {
        return false;
      }
    }
    for (int j = 0; j < n; j++) {
      a[j][i]--;
    }
    res.push_back({"col", i + 1});
    return true;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      while (a[i][j]) {
        if (n <= m) {
          if (row(i)) continue;
          if (col(j)) continue;
          cout << -1;
          return 0;
        } else {
          if (col(j)) continue;
          if (row(i)) continue;
          cout << -1;
          return 0;
        }
      }
    }
  }
  cout << res.size() << endl;
  for (const auto &[t, i]: res) {
    cout << t << " " << i << endl;
  }
}
