int main() {
  int n, m; cin >> n >> m;
  auto vec = getv<int, int, int>(m, 1);
  vector<vector<tuple<int, int, int>>> g(n + 1);
  vector<int> flows(n + 1);
  vector<int> ans(m, -1);
  for (int i = 1; i <= m; i ++) {
    auto [u, v, c] = vec[i];
    g[u].emplace_back(v, c, i);
    g[v].emplace_back(u, c, -i);
    flows[u] += c;
    flows[v] += c;
  }

  for (int i = 2; i < n; i ++)
    flows[i] /= 2;

  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (auto &[v, w, idx]: g[x]) if (ans[abs(idx) - 1] == -1) {
      ans[abs(idx) - 1] = (idx < 0);
      if ((flows[v] -= w) == 0)
        q.push(v);
    }
  }

  write(ans, "%d\n");
  return 0;
}
