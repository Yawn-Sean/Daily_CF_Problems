int main() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  for (auto [a, b]: getv<int, int>(n - 1)) {
    -- a, -- b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  long long ans = 0, c1 = 0, c0 = 0;
  auto dfs = [&] (auto self, int x, int f, int dep) -> int {
    (dep ? c1 : c0) ++;
    int res = 1;
    for (auto v: g[x]) if (v != f)
      res += self(self, v, x, ! dep);
    ans += 1ll * res * (n - res);
    return res;
  };
  dfs(dfs, 0, 0, 0);
  printf("%lld\n", (ans + c0 * c1) / 2);
  return 0;
}
