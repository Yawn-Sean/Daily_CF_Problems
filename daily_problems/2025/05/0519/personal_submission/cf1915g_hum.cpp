#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<array<int, 2>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector dist(n, vector(1001, -1ll));
  vector vis(n, vector(1001, false));
  priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<>> q;
  q.push({0, 0, a[0]});
  dist[0][a[0]] = 0;

  while (!q.empty()) {
    auto [d,u,c] = q.top();
    q.pop();
    if (vis[u][c]) continue;
    vis[u][c] = true;

    for (auto [v,w]: g[u]) {
      if (dist[v][c] == -1 or dist[v][c] > d + w * c) {
        dist[v][c] = d + w * c;
        q.push({dist[v][c], v, c});
      }
      if (dist[v][a[v]] == -1 or dist[v][a[v]] > d + w * c) {
        dist[v][a[v]] = d + w * c;
        q.push({dist[v][a[v]], v, a[v]});
      }
    }
  }
  long long res = 1e18;
  for (int i = 0; i < n; i++) {
    if (dist[n - 1][a[i]] != -1) {
      res = min(res, dist[n - 1][a[i]]);
    }
  }
  cout << res << endl;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
