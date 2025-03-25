#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<array<int, 2>>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  int m = ranges::max(deg);
  int s{};
  for (int i = 0; i < n; i++) {
    if (deg[i] == m) {
      s = i;
      break;
    }
  }
  cout << m << endl;

  vector<vector<int>> res(m);
  function<void(int, int, int)> dfs = [&](int u, int p, int d) {
    int t = 0;
    for (auto &[v,i]: g[u]) {
      if (v == p) continue;
      res[(d + t) % m].push_back(i + 1);
      dfs(v, u, d + t + 1);
      t++;
    }
  };
  dfs(s, s, 0);
  for (int i = 0; i < m; i++) {
    cout << res[i].size() << " ";
    for (int x: res[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
}
