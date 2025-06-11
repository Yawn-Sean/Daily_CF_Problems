int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<bool> rt(n + 1);
  for (auto [a, b]: getv<int, int>(m))
    g[a].emplace_back(b), rt[b] = true;

  auto q = getv(n);
  vector<bool> exist(n + 1);
  for (auto e: q)
    exist[e] = true;
  vector<int> ans;

  bool chk = true;
  auto dfs = [&] (auto self, int x, int f) -> void {
    if (exist[x])
      f = x;
    chk &= q[x - 1] == f;
    for (auto v: g[x])
      self(self, v, f);
    if (exist[x])
      ans.emplace_back(x);
  };

  for (int i = 1; i <= n; i ++) if (!rt[i])
    dfs(dfs, i, i);

  if (!chk)
    return puts("-1"), 0;
  printf("%d\n", (int)ans.size());
  write(ans, "%d\n");
  return 0;
}
