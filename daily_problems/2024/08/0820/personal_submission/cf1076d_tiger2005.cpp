int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> ans;
  vector<i64> dis(n, 1e18);
  vector<int> frm(n, 0);
  dis[0] = 0;

  vector<vector<tuple<int, int, int>>> g(n);
  for (auto [i, e]: index(getv<int, int, int>(m), 1)) {
    auto [a, b, c] = e;
    -- a, -- b;
    g[a].emplace_back(b, c, i);
    g[b].emplace_back(a, c, i);
  }

  priority_queue<pair<i64, int>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [l, x] = pq.top();
    pq.pop();
    if (l != - dis[x])
      continue;
    if (x != 0)
      ans.push_back(frm[x]);
    for (auto [v, w, id]: g[x])
      if (ckmin(dis[v], dis[x] + w))
        pq.push({- dis[v], v}), frm[v] = id;
  }
  if (n - 1 >= k)
    ans.resize(k);

  printf("%d\n", (int)ans.size());
  write(ans, "%d ");

  return 0;
}
