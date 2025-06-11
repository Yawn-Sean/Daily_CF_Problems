int main() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  for (auto [a, b]: getv<int, int>(n - 1)) {
    -- a, -- b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<Z> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i ++)
    fact[i] = fact[i - 1] * i;

  Z ans = n;
  auto dfs = [&] (auto self, int x, int f) -> void {
    int cnt = 0;
    for (auto v: g[x]) if (v != f) {
      self(self, v, x);
      ++ cnt;
    }
    ans *= fact[cnt + (x != 0)];
  };

  dfs(dfs, 0, 0);
  printf("%d\n", (int)ans);

  return 0;
}
