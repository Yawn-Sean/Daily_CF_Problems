int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (auto &[a, b]: getv<pair<int, int>>(m))
    g[a - 1].push_back(b - 1);

  auto dist = [&] (int s) {
    vector<int> res(n, -1);
    res[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (auto v: g[x]) if (res[v] == -1)
        res[v] = res[x] + 1, q.push(v);
    }
    return res;
  };
  vector<vector<int>> F, G(n, vector<int>(n)), H;
  for (int i = 0; i < n; i ++)
    F.push_back(dist(i));
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++)
      G[i][j] = F[j][i];
  H = F;
  vector<vector<pair<int, int>>> cand1(n), cand2(n);
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < 3; j ++) {
      auto ptr = max_element(ALL(F[i]));
      if (*ptr == 0)
        break;
      cand2[i].emplace_back(*ptr, ptr - F[i].begin());
      *ptr = -1;
    }
    for (int j = 0; j < 3; j ++) {
      auto ptr = max_element(ALL(G[i]));
      if (*ptr == 0)
        break;
      cand1[i].emplace_back(*ptr, ptr - G[i].begin());
      *ptr = -1;
    }
  }

  tuple<int, int, int, int> tp{0, 0, 0, 0};
  int ans = 0;
  for (int s = 0; s < n; s ++)
    for (int t = 0; t < n; t ++) if (s != t && H[s][t] != -1) {
      for (auto [du, u]: cand1[s]) for (auto [dv, v]: cand2[t]) {
        if (u == v || u == t || v == s)
          continue;
        int dis = du + H[s][t] + dv;
        if (dis > ans)
          ans = dis, tp = {u, s, t, v};
      }
    }

  auto &[a, b, c, d] = tp;
  printf("%d %d %d %d", a + 1, b + 1, c + 1, d + 1);
  return 0;
}
