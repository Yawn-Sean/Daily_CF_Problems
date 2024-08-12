int main() {
  int n, m; cin >> n >> m;
  auto a = getv<long long>(n);
  vector<vector<int>> g(m);
  for (auto [idx, val]: index(a))
    g[val % m].push_back(idx);
  vector<int> fa(m);
  auto getf = [&] (auto self, int x) -> int {
    return x == fa[x] ? x : fa[x] = self(self, fa[x]);
  };
  for (int i = 0; i < m; i ++)
    fa[i] = i;
  for (int i = 0; i < m; i ++) if ((int)g[i].size() >= n / m)
    fa[i] = (i + 1) % m;
  long long ans = 0;
  for (int i = 0; i < m; i ++) {
    while ((int)g[i].size() > n / m) {
      int idx = g[i].back();
      g[i].pop_back();
      int y = getf(getf, i);
      int delta = (y + m - i) % m;
      a[idx] += delta;
      ans += delta;
      g[y].push_back(idx);
      if ((int)g[y].size() == n / m)
        fa[y] = (y + 1) % m;
    }
  }
  printf("%lld\n", ans);
  write(a, "%lld ", "\n");
  return 0;
}
