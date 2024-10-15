int main() {
  int n, m; cin >> n >> m;
  if (m == 0) {
    i64 ans = 1ll * n * (n - 1) / 2 * (n - 2) / 3;
    printf("3 %lld\n", ans);
    return 0;
  }
  vector<vector<int>> g(n + 1);
  for (auto [a, b]: getv<int, int>(m))
    g[a].push_back(b),
    g[b].push_back(a);
  vector<int> col(n + 1, -1);

  int c0 = 0, c1 = 0;
  auto dfs = [&] (auto self, int x) -> void {
    (col[x] ? c1 : c0) ++;
    for (auto v: g[x]) {
      if (col[v] == col[x]) {
        printf("0 1\n");
        exit(0);
      }
      if (col[v] == -1)
        col[v] = !col[x], self(self, v);
    }
  };

  i64 ans = 0;
  int mx = 2;
  for (int i = 1; i <= n; i ++) if (col[i] == -1) {
    col[i] = 0; c0 = c1 = 0;
    dfs(dfs, i);
    if (c0 + c1 == 1)
      continue;
    i64 u = 0, v = 0;
    if (c0 == 1 && c1 == 1)
      u = 2, v = n - 2;
    else
      u = 1, v = (1ll * c0 * (c0 - 1) + 1ll * c1 * (c1 - 1)) / 2;
    if (mx > u)
      mx = u, ans = 0;
    if (mx == u)
      ans += v;
  }
  printf("%d %lld\n", mx, ans);
  return 0;
}
