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
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector cnt(2, vector(n, 0ll));
  vector dis(2, vector(n, 0ll));
  function<void(int, int)> bfs = [&](int s, int c) {
    queue<int> q;
    vector<bool> vis(n);
    vis[s] = true;
    cnt[c][s] = 1;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v: g[u]) {
        if (!vis[v]) {
          vis[v] = true;
          dis[c][v] = dis[c][u] + 1;
          q.push(v);
        }
        if (dis[c][v] == dis[c][u] + 1) {
          cnt[c][v] += cnt[c][u];
        }
      }
    }
  };
  bfs(0, 0);
  bfs(n - 1, 1);

  long long ma = cnt[0][n - 1];
  for (int i = 1; i < n - 1; i++) {
    if (dis[0][i] + dis[1][i] == dis[0][n - 1]) {
      ma = max(ma, cnt[0][i] * cnt[1][i] * 2);
    }
  }
  cout << setprecision(20) << 1.0 * ma / cnt[0][n - 1] << '\n';
}
