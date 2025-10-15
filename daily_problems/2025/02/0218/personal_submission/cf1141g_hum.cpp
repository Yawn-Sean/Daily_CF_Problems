#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<vector<array<int, 2>>> g(n);
  vector<int> deg(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
    deg[u]++;
    deg[v]++;
  }
  ranges::sort(deg, greater());

  int d = deg[k];
  cout << d << endl;
  vector<int> res(n - 1);

  function<void(int, int, int)> dfs = [&](int u, int p, int c) {
    for (auto [v,i]: g[u]) {
      if (v == p) {
        continue;
      }
      c++;
      res[i] = c % d + 1;
      dfs(v, u, c);
    }
  };
  dfs(0, 0, 0);
  for (int i = 0; i < n - 1; ++i) {
    cout << res[i] << " \n"[i == n - 2];
  }
}
