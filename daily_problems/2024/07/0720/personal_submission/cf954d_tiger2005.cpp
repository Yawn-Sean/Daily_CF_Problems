int main() {
  int n, m, s, t; cin >> n >> m >> s >> t;
  vector<vector<int>> g(n);
  set<pair<int, int>> st;
  for (auto [a, b]: getv<int, int>(m)) {
    -- a, -- b;
    if (a > b)
      swap(a, b);
    st.insert({a, b});
    g[a].push_back(b);
    g[b].push_back(a);
  }
  auto get = [&] (int s) {
    queue<int> q;
    q.push(s);
    vector<int> res(n, -1);
    res[s] = 0;
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (auto v: g[x]) if (res[v] == -1)
        res[v] = res[x] + 1, q.push(v);
    }
    return res;
  };
  auto vs = get(s - 1), vt = get(t - 1);
  int len = vs[t - 1], ans = 0;
  for (int i = 0; i < n; i ++)
    for (int j = i + 1; j < n; j ++) {
      int nd = min(
        vs[i] + vt[j],
        vt[i] + vs[j]
      ) + 1;
      ans += (nd >= len) && st.count({i, j}) == 0;
    }
  printf("%d", ans);
  return 0;
}
