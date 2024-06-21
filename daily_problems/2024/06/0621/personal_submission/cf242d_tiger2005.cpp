int main() {
  int n, m; cin >> n >> m;
  vector<int> ans;
  vector<vector<int>> g(n);
  for (auto [a, b]: getv<int, int>(m)) {
    -- a; -- b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  auto a = getv(n);
  vector<int> vec;
  for (int i = 0; i < n; i ++) if (a[i] == 0)
    vec.push_back(i);
  while (!vec.empty()) {
    int x = vec.back();
    vec.pop_back();
    ans.push_back(x + 1);
    -- a[x];
    for (auto v: g[x])
      if (-- a[v] == 0)
        vec.push_back(v);
  }
  printf("%d\n", (int)ans.size());
  for (auto e: ans)
    printf("%d ", e);
}
