#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct DSU {
  vector<int> f, siz;

  DSU() {
  }

  DSU(int n) {
    init(n);
  }

  void init(int n) {
    f.resize(n);
    ranges::iota(f, 0);
    siz.assign(n, 1);
  }

  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    siz[x] += siz[y];
    f[y] = x;
    return true;
  }

  int size(int x) {
    return siz[find(x)];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<array<int, 3>> edges(m);
  vector<vector<pair<int, int>>> path(n);
  DSU uf(n);

  for (auto &[u, v, w]: edges) {
    cin >> u >> v >> w;
    u--, v--;
    path[u].emplace_back(v, w);
    path[v].emplace_back(u, w);
    uf.merge(u, v);
  }

  long long ans = 0;
  vector<int> chosen;

  for (auto &[u, v, w]: edges) {
    if (uf.find(u) == uf.find(0)) {
      chosen.emplace_back(w);
    }
  }

  ranges::sort(chosen);

  for (int i = 0; i < chosen.size(); i++) {
    if (i < k) {
      ans += chosen[i];
    }
  }

  long long inf = 1e15;
  vector<long long> dis(n, inf);
  dis[0] = 0;

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (dis[u] == d) {
      for (auto &[v, w]: path[u]) {
        if (dis[u] + w < dis[v]) {
          dis[v] = dis[u] + w;
          pq.push({dis[v], v});
        }
      }
    }
  }

  ans = min(ans, dis[n - 1]);

  cout << ans << '\n';
}
