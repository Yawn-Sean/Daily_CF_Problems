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
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> res(n);
  res[0] = 1;
  function<void(int, int)> dfs = [&](int u, int p) {
    int cnt{};
    for (int v: g[u]) {
      if (v == p) {
        continue;
      }
      ++cnt;
      while (cnt == res[u] || cnt == res[p]) {
        cnt++;
      }
      res[v] = cnt;
      dfs(v, u);
    }
  };
  dfs(0, 0);
  cout << ranges::max(res) << endl;
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
}
