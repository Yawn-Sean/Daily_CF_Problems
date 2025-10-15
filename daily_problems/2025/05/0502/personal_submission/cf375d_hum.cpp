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
  vector g(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  vector<int> cur(n);
  int res{};
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (g[i][j] == '1') {
        cur[i]++;
      } else {
        cur[i] = 0;
      }
    }
    vector<int> t = cur;
    ranges::sort(t, greater<int>());
    for (int i = 0; i < n; i++) {
      res = max(res, t[i] * (i + 1));
    }
  }
  cout << res << endl;
}
