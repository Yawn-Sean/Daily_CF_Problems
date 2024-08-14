int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n + 1);
  for (auto [a, b]: getv<int, int>(m))
    g[a].push_back(b),
    g[b].push_back(a);
  vector<int> fa(n + 1);
  pair<int, int> mx;
  auto dfs = [&] (auto self, int x, int f, int d) -> void {
    ckmax(mx, {d, x});
    fa[x] = f;
    for (auto v: g[x]) if (v != f)
      self(self, v, x, d + 1);
  };
  vector<pair<int, int>> vec;
  for (int i = 1; i <= n; i ++) if (!fa[i]) {
    mx = {-1, 0};
    dfs(dfs, i, i, 0);
    int rt = mx.second; mx = {-1, 0};
    dfs(dfs, rt, rt, 0); rt = mx.second;
    for (int j = 0; j < mx.first / 2; j ++)
      rt = fa[rt];
    vec.emplace_back(mx.first, rt);
  }
  auto &[num, center] = *max_element(ALL(vec));
  int ans = num, mxv = (num + 1) / 2;

  for (auto [a, b]: vec) if (b != center)
    a = (a + 1) / 2 + 1,
    ckmax(ans, mxv + a),
    ckmax(mxv, a);
  printf("%d\n", ans);
  for (auto [a, b]: vec) if (b != center)
    printf("%d %d\n", b, center);
  return 0;
}
