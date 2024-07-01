int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> v, g(n);
  for (int i = 0; i < n; i ++)
    v.push_back(getv(read()));
  for (auto [a, b]: getv<int, int>(n - 1))
    g[a - 1].push_back(b - 1),
    g[b - 1].push_back(a - 1);
  vector<int> ans(m);
  queue<int> q;
  q.push(0);
  vector<bool> vis(n);
  vis[0] = true;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    vector<int> cvd;
    vector<int> fog;

    for (auto e: v[x]) {
      -- e;
      if (ans[e] != 0)
        cvd.push_back(ans[e]);
      else
        fog.push_back(e);
    }

    sort(cvd); unique(cvd);
    int ptr = 0, cur = 1;
    for (auto e: fog) {
      while (ptr != (int)cvd.size() && cvd[ptr] == cur)
        ++ ptr, ++ cur;
      ans[e] = cur ++;
    }
    for (auto v: g[x]) if (!vis[v])
      vis[v] = true, q.push(v);
  }
  for (auto &e: ans)
    if (e == 0) e = 1;
  printf("%d\n", *max_element(ALL(ans)));
  write(ans, "%d ");
  return 0;
}
