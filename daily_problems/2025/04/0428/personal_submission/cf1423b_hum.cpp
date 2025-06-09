#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


template<class T>
struct MaxFlow {
  struct _Edge {
    int to;
    T cap;

    _Edge(int to, T cap) : to(to), cap(cap) {
    }
  };

  int n;
  vector<_Edge> e;
  vector<vector<int>> g;
  vector<int> cur, h;

  MaxFlow() {
  }

  MaxFlow(int n) {
    init(n);
  }

  void init(int n) {
    this->n = n;
    e.clear();
    g.assign(n, {});
    cur.resize(n);
    h.resize(n);
  }

  bool bfs(int s, int t) {
    h.assign(n, -1);
    queue<int> que;
    h[s] = 0;
    que.push(s);
    while (!que.empty()) {
      const int u = que.front();
      que.pop();
      for (int i: g[u]) {
        auto [v, c] = e[i];
        if (c > 0 && h[v] == -1) {
          h[v] = h[u] + 1;
          if (v == t) {
            return true;
          }
          que.push(v);
        }
      }
    }
    return false;
  }

  T dfs(int u, int t, T f) {
    if (u == t) {
      return f;
    }
    auto r = f;
    for (int &i = cur[u]; i < int(g[u].size()); ++i) {
      const int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        auto a = dfs(v, t, min(r, c));
        e[j].cap -= a;
        e[j ^ 1].cap += a;
        r -= a;
        if (r == 0) {
          return f;
        }
      }
    }
    return f - r;
  }

  void addEdge(int u, int v, T c) {
    g[u].push_back(e.size());
    e.emplace_back(v, c);
    g[v].push_back(e.size());
    e.emplace_back(u, 0);
  }

  T flow(int s, int t) {
    T ans = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      ans += dfs(s, t, numeric_limits<T>::max());
    }
    return ans;
  }

  vector<bool> minCut() {
    vector<bool> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = (h[i] != -1);
    }
    return c;
  }

  struct Edge {
    int from;
    int to;
    T cap;
    T flow;
  };

  vector<Edge> edges() {
    vector<Edge> a;
    for (int i = 0; i < e.size(); i += 2) {
      Edge x;
      x.from = e[i + 1].to;
      x.to = e[i].to;
      x.cap = e[i].cap + e[i + 1].cap;
      x.flow = e[i + 1].cap;
      a.push_back(x);
    }
    return a;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> g(m);
  for (int i = 0; i < m; i++) {
    cin >> g[i][0] >> g[i][1] >> g[i][2];
    g[i][0]--, g[i][1]--;
  }

  int inf = 1e9;
  int l{}, r{inf};
  while (l < r) {
    int mid = l + r >> 1;
    MaxFlow<int> mf(2 * n + 2);
    int s{2 * n}, e{2 * n + 1};
    for (int i = 0; i < m; i++) {
      if (g[i][2] <= mid) {
        mf.addEdge(g[i][0], n + g[i][1], 1);
      }
    }
    for (int i = 0; i < n; i++) {
      mf.addEdge(s, i, 1);
      mf.addEdge(n + i, e, 1);
    }
    if (mf.flow(s, e) == n) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l == inf) {
    cout << -1 << endl;
  } else {
    cout << l << endl;
  }
}
