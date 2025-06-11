const int N = 1005;
string level[N][11];
vector<int> G[N];

struct edge {
  int u, v;
  ll weight;
  edge(){};
  edge(int u, int v, int w) : u(u), v(v), weight(w) {}
  bool operator<(const edge &o) const { return weight < o.weight; }
};

void solve() {
  int n, m, k, w;
  cin >> n >> m >> k >> w;
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> level[i][j];
    }
  }
  vector<edge> edg;
  for (int i = 1; i <= k; i++) {
    edg.emplace_back(0, i, n * m);
  }
  auto calcDiff = [&](int a, int b) -> ll {
    ll diff = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (level[a][i][j] != level[b][i][j])
          diff++;
      }
    }
    return diff * ll(w);
  };
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      edg.emplace_back(i, j, calcDiff(i, j));
    }
  }
  sort(all(edg));
  UF dsu(k + 1);
  vector<int> p(k + 1);
  ll ans = 0;
  for (edge &e : edg) {
    int u = e.u, v = e.v, weight = e.weight;
    if (!dsu.sameSet(u, v)) {
      G[u].emplace_back(v);
      G[v].emplace_back(u);
      dsu.join(u, v);
      ans += weight;
    }
  }
  auto dfs = [&](auto &&dfs, int u, int fa) -> void {
    if (u != 0) {
      p[u] = fa;
      cout << u << " " << fa << "\n";
    }
    for (int v : G[u]) {
      if (v != fa)
        dfs(dfs, v, u);
    }
  };
  cout << ans << "\n";
  dfs(dfs, 0, -1);
}
