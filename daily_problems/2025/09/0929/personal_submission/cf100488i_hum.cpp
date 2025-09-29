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

  int n, m, c;
  cin >> n >> m >> c;

  vector<vector<int>> path(n, vector<int>(n, 0));

  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    path[u][v] = 1;
    path[v][u] = 1;
  }

  vector<int> cols(n, 0);
  int col = 1;

  auto dfs = [&](auto &self, int u) -> void {
    cols[u] = col;

    for (int v = 0; v < n; v++) {
      if (!path[u][v] && !cols[v]) {
        self(self, v);
      }
    }
  };

  for (int i = 0; i < n; i++)
    if (!cols[i]) dfs(dfs, i), col++;

  if (col - 1 > c) return cout << -1, 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (path[i][j] == (cols[i] == cols[j])) return cout << -1, 0;
    }
  }

  for (auto &v: cols) cout << v << ' ';

  return 0;
}
