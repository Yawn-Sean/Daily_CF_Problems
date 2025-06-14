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
  vector<vector<int>> g(n);
  for (int i = 1; i <= n - 1; ++i) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
  vector<int> dfs_order;
  vector<int> idx(n), l(n), r(n);
  function<void(int)> dfs = [&](int u) {
    idx[u] = dfs_order.size();
    l[u] = dfs_order.size();
    dfs_order.push_back(u);
    for (auto v: g[u]) {
      dfs(v);
    }
    r[u] = dfs_order.size();
  };
  dfs(0);
  for (int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    u--, k--;
    if (r[u] - l[u] <= k) {
      cout << -1 << '\n';
    } else {
      cout << dfs_order[idx[u] + k] + 1 << '\n';
    }
  }
}
