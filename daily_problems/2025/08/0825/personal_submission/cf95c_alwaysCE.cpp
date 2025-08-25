#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// Rename to cf95c_alwaysCE.cpp
i64 inf = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int st, ed;
  cin >> st >> ed;
  --st; --ed;
  vector<vector<pair<int, i64>>> path(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    path[u].emplace_back(v, w);
    path[v].emplace_back(u, w);
  }
  // taxi at road i, with cost c[i] and maximum travel distance t[i]
  vector<i64> t(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> c[i];
  }

  vector<vector<i64>> dist(n, vector<i64>(n, inf));
  auto dijkstra = [&](int start, vector<i64>& dist,
                      vector<vector<pair<int, i64>>>& adj) {
    priority_queue<pair<i64, int>> q;
    q.push(make_pair(0ll, start));
    dist[start] = 0;
    while (!q.empty()) {
      int dis, u;
      tie(dis, u) = q.top();
      q.pop();
      dis = -dis;
      if (dis > dist[u]) {
        continue;
      }
      for (auto [v, w] : adj[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          q.push(make_pair(-dist[v], v));
        }
      }
    }
  };

  for (int i = 0; i < n; i++) {
    dijkstra(i, dist[i], path);
  }

  vector<vector<pair<int, i64>>> newPath(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] <= t[i]) {
        newPath[i].emplace_back(j, c[i]);
      }
    }
  }

  vector<i64> newDist(n, inf);
  dijkstra(st, newDist, newPath);
  cout << (newDist[ed] == inf ? -1 : newDist[ed]) << endl;
  return 0;
}
