int fa[100010][20];

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n), t(n);
  vector<pair<int, int>> es;

  for (auto [a, b]: getv<int, int>(m)) {
    -- a, -- b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> dep(n);
  vector<int> col(n);
  vector<bool> mark(n);

  for (int i = 0; i < n; i ++)
    col[i] = i;

  auto dfs = [&] (auto self, int x, int f) -> void {
    dep[x] = dep[f] + 1;
    for (auto v: g[x]) if (v != f) {
      if (dep[v] > dep[x]) {
        mark[x] = true;
        int u = v;
        for (; u != x; u = fa[u][0])
          col[u] = x;
      }
      else if (!dep[v])
        fa[v][0] = x, es.emplace_back(x, v), self(self, v, x);
    }
  };

  dfs(dfs, 0, 0);
  for (int i = 0; i < n; i ++)
    fa[i][0] = 0;
  for (auto [a, b]: es) {
    a = col[a], b = col[b];
    if (a == b)
      continue;
    t[a].push_back(b);
    fa[b][0] = a;
  }

  for (int i = 1; i < 20; i ++)
    for (int j = 0; j < n; j ++)
      fa[j][i] = fa[fa[j][i - 1]][i - 1];

  auto lca = [&] (int x, int y) {
    if (dep[x] < dep[y])
      swap(x, y);
    for (int i = 19; i >= 0; i --) if (dep[fa[x][i]] >= dep[y])
      x = fa[x][i];
    if (x == y)
      return x;
    for (int i = 19; i >= 0; i --) if (fa[x][i] != fa[y][i])
      x = fa[x][i], y = fa[y][i];
    return fa[x][0];
  };

  vector<int> num(n);
  vector<int> pw(n + 1);
  pw[0] = 1;
  for (int i = 1; i <= n; i ++)
    pw[i] = pw[i - 1] * 2 % (int)(1e9 + 7);

  auto dfs2 = [&] (auto self, int x) -> void {
    dep[x] = dep[fa[x][0]] + 1;
    num[x] = num[fa[x][0]] + mark[x];
    for (auto v: t[x])
      self(self, v);
  };
  dfs2(dfs2, 0);

  multiCase() {
    int a, b; cin >> a >> b;
    -- a, -- b;
    a = col[a], b = col[b];
    int l = lca(a, b);
    printf("%d\n", pw[num[a] + num[b] - num[l] - (l ? num[fa[l][0]] : 0)]);
  }

  return 0;
}
