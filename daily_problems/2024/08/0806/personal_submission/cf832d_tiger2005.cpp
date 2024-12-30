int fa[100010][20];
vector<int> g[100010];

int main() {
  int n, q; cin >> n >> q;
  vector<int> dep(n + 1);
  fa[1][0] = 1;
  for (int i = 2; i <= n; i ++) {
    cin >> fa[i][0];
    g[fa[i][0]].push_back(i);
  }
  auto dfs = [&] (auto self, int x) -> void {
    for (auto v: g[x])
      dep[v] = dep[x] + 1, self(self, v);
  };
  dfs(dfs, 1);
  for (int i = 1; i < 20; i ++)
    for (int j = 1; j <= n; j ++)
      fa[j][i] = fa[fa[j][i - 1]][i - 1];
  auto lca = [&] (int x, int y) {
    if (dep[x] < dep[y])
      swap(x, y);
    for (int i = 19; i >= 0; i --)
      if (dep[fa[x][i]] >= dep[y])
        x = fa[x][i];
    if (x == y)
      return x;
    for (int i = 19; i >= 0; i --)
      if (fa[x][i] != fa[y][i])
        x = fa[x][i], y = fa[y][i];
    return fa[x][0];
  };
  auto dis = [&] (int x, int y) {
    return dep[x] + dep[y] - 2 * dep[lca(x, y)];
  };
  while (q --) {
    auto [a, b, c] = reads<int, int, int>();
    int x = dis(a, b), y = dis(b, c), z = dis(c, a);
    printf("%d\n", (x + y + z) / 2 - min({x, y, z}) + 1);
  }
  return 0;
}
