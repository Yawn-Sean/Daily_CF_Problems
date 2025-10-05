#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    // dist(1, x1) < dist(1, x2) < ...
    vector<int> xs(k);
    for (int i = 0; i < k; i++) {
      cin >> xs[i];
      xs[i]--;
    }

    vector<vector<int>> path(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      path[u].push_back(v);
      path[v].push_back(u);
    }

    int add = 0;
    int last = 0;
    // 加入(1,x1),(x1,x2),...,(x_k-1, xk)之后
    // 假设原来的图满足要求 那么加入之后仍然满足需求
    // 因此只需要检查这个构造是否合法
    vector<pair<int, int>> new_edges;
    auto add_edge = [&](int u, int v) {
      path[u].push_back(v);
      path[v].push_back(u);
      new_edges.emplace_back(u, v);
    };

    for (int i = 0; i < k; i++) {
      if (xs[i] != last) {
        add_edge(last, xs[i]);
        last = xs[i];
        add++;
      }
    }

    auto dijkstra = [&](int start) {
      vector<int> dist(n, INT_MAX);
      dist[start] = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
      pq.emplace(0, start);
      while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
          continue;
        }
        for (auto v : path[u]) {
          if (dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
            pq.emplace(dist[v], v);
          }
        }
      }
      return dist;
    };

    auto dis = dijkstra(0);
    bool ok = true;
    for (int i = 0; i < k - 1; i++) {
      if (dis[xs[i]] >= dis[xs[i + 1]]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << add << endl;
      for (auto [u, v] : new_edges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
      }
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}
