int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(n);
  for (auto [a, b]: getv<int, int>(m)) {
    -- a, -- b;
    g[a].push_back(b);
  }
  long long ans = 0;
  for (int i = 0; i < n; i ++) {
    vector<int> cnt(n);
    for (int j: g[i])
      for (int k: g[j])
        if (i != k)
          ans += (cnt[k] ++);
  }
  printf("%lld", ans);
  return 0;
}
