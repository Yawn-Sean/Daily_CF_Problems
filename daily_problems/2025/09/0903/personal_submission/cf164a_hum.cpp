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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> g(n), rg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  vector vis1(n, 0), vis2(n, 0);
  function<void(int)> dfs1 = [&](int u) {
    vis1[u] = 1;
    for (auto v: g[u]) {
      if (!vis1[v] && a[v] != 1) {
        dfs1(v);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      dfs1(i);
    }
  }
  function<void(int)> dfs2 = [&](int u) {
    vis2[u] = 1;
    if (a[u] == 1) {
      return;
    }
    for (auto v: rg[u]) {
      if (!vis2[v]) {
        dfs2(v);
      }
    }
  };
  for (int i = 0; i < n; i++) {
    if (a[i] == 2) {
      dfs2(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (vis1[i] && vis2[i]) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
}
