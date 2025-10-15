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

  int n, x;
  cin >> n >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> d1(n);
  d1[0] = 0;
  function<void(int, int)> dfs1 = [&](int u, int p) {
    for (auto v: g[u]) {
      if (v == p) continue;
      d1[v] += d1[u] + 1;
      dfs1(v, u);
    }
  };
  dfs1(0, 0);
  vector<int> d2(n);
  d2[x - 1] = 0;
  function<void(int, int)> dfs2 = [&](int u, int p) {
    for (auto v: g[u]) {
      if (v == p) continue;
      d2[v] = d2[u] + 1;
      dfs2(v, u);
    }
  };
  dfs2(x - 1, x - 1);
  int res{};
  for (int i = 0; i < n; ++i) {
    if (d2[i] < d1[i]) {
      res = max(res, 2 * d1[i]);
    }
  }
  cout << res << '\n';
}
