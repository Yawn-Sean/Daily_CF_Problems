int main() {
  int n, m; cin >> n >> m;
  vector<vector<tuple<int, int, int>>> g(n);
  vector<int> vl, vr;
  for (auto [a, b, l, r]: getv<int, int, int, int>(m))
    g[a - 1].emplace_back(b - 1, l, r), vl.emplace_back(l),
    g[b - 1].emplace_back(a - 1, l, r), vr.emplace_back(r);
  vector<int> vp;
  int ans = 0;
  
  auto check = [&] (int l, int r) {
    if (l > r)
      return true;
    vector<bool> res(n);
    queue<int> q;
    q.push(0);
    res[0] = true;
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (auto [y, ll, rr]: g[x])
        if (!res[y] && ll <= l && r <= rr) {
          if (y == n - 1)
            return true;
          res[y] = true;
          q.push(y);
        }
    }
    return false;
  };

  vl = uniqued(sorted(vl));
  vr = uniqued(sorted(vr));

  int l = 0, r = -1;
  for (; l < (int)vl.size(); l ++) {
    while (r != (int)vr.size() - 1 && check(vl[l], vr[r + 1]))
      ++ r;
    if (r != -1)
      ans = max(ans, vr[r] - vl[l] + 1);
  }

  if (ans != 0)
    printf("%d", ans);
  else
    puts("Nice work, Dima!");
  return 0;
}
