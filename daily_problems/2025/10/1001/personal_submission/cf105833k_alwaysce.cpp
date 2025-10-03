#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<int, i64>>> path(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    i64 c;
    cin >> x >> y >> c;
    x--;
    y--;
    path[x].emplace_back(y, c);
    path[y].emplace_back(x, c);
  }

  auto dijkstra = [&](int start) {
    vector<i64> dist(n, LLONG_MAX);
    dist[start] = 0;
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d > dist[u]) {
        continue;
      }
      for (auto [v, w] : path[u]) {
        i64 nd = dist[u] + w;
        if (nd < dist[v]) {
          dist[v] = nd;
          pq.emplace(nd, v);
        }
      }
    }
    return dist;
  };

  auto dist_from_start = dijkstra(0);
  i64 ans0 = dist_from_start[n - 1];

  vector<char> vis(n, 0);
  queue<int> q;
  vis[0] = 1;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, w] : path[u])
      if (!vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
  }

  vector<i64> costs;
  costs.reserve(m);
  for (int u = 0; u < n; u++)
    if (vis[u]) {
      for (auto [v, w] : path[u])
        if (vis[v] && u < v) {
          costs.push_back(w);
        }
    }
  sort(costs.begin(), costs.end());
  i64 ans1 = 0;
  for (int i = 0; i < min(k, (int)costs.size()); i++) {
    ans1 += costs[i];
  }

  cout << min(ans0, ans1) << '\n';
  return 0;
}
