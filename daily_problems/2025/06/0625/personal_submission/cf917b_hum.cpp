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
  vector<vector<array<int, 2>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    g[u - 1].push_back({v - 1, c - 'a'});
  }
  vector dp(n, vector(n, vector<int>(26, -1)));
  function<int(int, int, int)> dfs = [&](int u, int j, int cur) -> int {
    int &res = dp[u][j][cur];
    if (res != -1) {
      return res;
    }
    for (auto [v,w]: g[u]) {
      if (w < cur) {
        continue;
      }
      if (!dfs(j, v, w)) {
        return res = 1;
      }
    }
    return res = 0;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dfs(i, j, 0)) {
        cout << "A";
      } else {
        cout << "B";
      }
    }
    cout << endl;
  }
}
