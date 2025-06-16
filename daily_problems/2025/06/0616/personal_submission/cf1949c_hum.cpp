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
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      pq.push({1, i});
    }
  }
  vector val(n, 1);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    for (auto v: g[u]) {
      if (val[v] > 0) {
        if (val[v] < val[u]) {
          cout << "NO";
          return 0;
        }
        val[v] += val[u];
        val[u] = 0;
        if (--deg[v] == 1) {
          pq.push({val[v], v});
        }
      }
    }
  }
  cout << "YES\n";
}
