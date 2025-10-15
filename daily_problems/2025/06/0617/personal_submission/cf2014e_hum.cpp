#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
i64 inf = 1e18;

vector<i64> dijkstra(vector<vector<pair<int, i64>>> graph, int source) {
  int n = graph.size();
  vector<i64> dist(n, inf);
  dist[source] = 0;
  priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
  vector<bool> vis(n, false);
  pq.emplace(dist[source], source);
  while (!pq.empty()) {
    i64 d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    for (auto &[v, w]: graph[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        pq.emplace(dist[v], v);
      }
    }
  }
  return dist;
}

void solve() {
  int n, m, h;
  cin >> n >> m >> h;
  vector<int> hs(h);
  for (int i = 0; i < h; i++) {
    cin >> hs[i];
    hs[i]--;
  }
  vector<vector<pair<int, i64>>> graph(n * 2);
  for (int i = 0; i < m; i++) {
    int u, v;
    i64 w;
    cin >> u >> v >> w;
    u--, v--;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
    graph[u + n].emplace_back(v + n, w / 2);
    graph[v + n].emplace_back(u + n, w / 2);
  }
  for (int i = 0; i < h; i++) {
    graph[hs[i]].emplace_back(hs[i] + n, 0);
  }

  vector<i64> dist1 = dijkstra(graph, 0);
  vector<i64> dist2 = dijkstra(graph, n - 1);

  i64 res = inf;
  for (int i = 0; i < n; i++) {
    res = min(res, max(min(dist1[i], dist1[i + n]), min(dist2[i], dist2[i + n])));
  }
  if (res == inf) {
    cout << -1 << '\n';
  } else {
    cout << res << '\n';
  }
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
