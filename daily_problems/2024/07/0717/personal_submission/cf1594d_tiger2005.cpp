int main() {
  multiCase() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vp;
    Union un(n);
    for (auto [a, b, s]: getv<int, int, string>(m)) {
      if (s[0] == 'c')
        un.link(a, b);
      else
        vp.emplace_back(a, b);
    }
    vector<vector<int>> g(n + 1);
    bool flg = true;

    for (auto [a, b]: vp)
      g[un[a]].push_back(un[b]), g[un[b]].push_back(un[a]), flg &= (un[a] != un[b]);

    if (!flg) {
      puts("-1");
      continue;
    }

    vector<int> col(n + 1, -1);
    vector<int> siz(n + 1);
    for (int i = 1; i <= n; i ++)
      ++ siz[un[i]];

    int a0 = 0, a1 = 0;
    auto dfs = [&] (auto self, int x, int f) -> bool {
      (col[x] ? a1 : a0) += siz[x];
      for (auto v: g[x]) if (v != f) {
        if (col[v] == col[x])
          return false;
        if (col[v] == -1) {
          col[v] = 1 - col[x];
          if (!self(self, v, x))
            return false;
        }
      }
      return true;
    };
    int ans = 0;
    for (int i = 1; i <= n; i ++) if (un[i] == i && col[i] == -1)
      a0 = a1 = 0, col[i] = 0,
      flg &= dfs(dfs, i, i),
      ans += max(a0, a1);
    if (!flg) {
      puts("-1");
      continue;
    }
    printf("%d\n", ans);
  }
  return 0;
}
