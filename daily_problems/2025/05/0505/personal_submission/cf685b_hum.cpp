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

  int n, q;
  cin >> n >> q;
  vector<int> par(n);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    cin >> par[i];
    par[i]--;
    g[par[i]].push_back(i);
  }

  vector<int> sz(n, 1);
  function<void(int)> dfs = [&](int u) {
    for (auto v: g[u]) {
      dfs(v);
      sz[u] += sz[v];
    }
  };
  dfs(0);

  vector<int> res(n);
  function<void(int)> dfs1 = [&](int u) {
    int v = -1;
    for (auto nv: g[u]) {
      dfs1(nv);
      if (v == -1 || sz[nv] > sz[v]) {
        v = nv;
      }
    }
    if (v == -1) {
      res[u] = u;
    } else {
      v = res[v];
      while (sz[v] * 2 < sz[u]) {
        v = par[v];
      }
      res[u] = v;
    }
  };
  dfs1(0);

  while (q--) {
    int u;
    cin >> u;
    cout << res[--u] + 1 << '\n';
  }
}
