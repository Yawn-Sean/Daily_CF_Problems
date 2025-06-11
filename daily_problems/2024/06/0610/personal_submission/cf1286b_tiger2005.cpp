int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> c(n + 1), a(n + 1);
  vector<int> cur(n + 1);

  for (int i = 1, fa; i <= n; i ++) {
    cin >> fa >> c[i];
    g[fa].push_back(i);
  }

  auto dfs = [&] (auto self, int x) -> vector<int> {
    vector<int> res;
    for (auto v: g[x]) {
      for (auto e: self(self, v))
        res.push_back(e);
    }
    if ((int)res.size() < c[x]) {
      puts("NO");
      exit(0);
    }
    res.insert(res.begin() + c[x], x);
    return res;
  };

  auto vec = dfs(dfs, g[0][0]);
  for (int i = 0; i < n; i ++)
    a[vec[i]] = i + 1;
  puts("YES");
  for (int i = 1; i <= n; i ++)
    printf("%d ", a[i]);
  return 0;
}
