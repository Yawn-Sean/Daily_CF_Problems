#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using i64 = long long;

vector<i64> dijkstra(vector<vector<pair<int, i64>>> graph, int source) {
  int n = graph.size();
  vector<i64> dist(n, LONG_MAX);
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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<pair<int, i64>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    g[i].emplace_back(i + 1, 1);
    g[i + 1].emplace_back(i, 1);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    g[i].emplace_back(x - 1, 1);
  }
  vector<i64> dis = dijkstra(g, 0);
  for (int i = 0; i < n; i++) {
    cout << dis[i] << " ";
  }
}
