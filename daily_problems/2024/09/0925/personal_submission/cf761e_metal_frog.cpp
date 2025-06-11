ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> tree(n + 1);
  vector<pair<ll, ll>> ans(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }
  bool flag = true;
  ans[1].first = 0, ans[1].second = 0;
  auto dfs = [&](auto &&dfs, int u, int fa, int dir, ll len) -> void {
    if (sz(tree[u]) > 4) {
      flag = false;
      return;
    }
    queue<int> availableDir;
    for (int i = 0; i < 4; i++) {
      if (dir == -1)
        availableDir.push(i);
      else {
        if (dx[i] != 0 && dx[i] != -dx[dir]) {
          availableDir.push(i);
        } else if (dy[i] != 0 && dy[i] != -dy[dir]) {
          availableDir.push(i);
        }
      }
    }
    for (int v : tree[u]) {
      if (v == fa)
        continue;
      int d = availableDir.front();
      availableDir.pop();
      ans[v].first = ans[u].first + dx[d] * len;
      ans[v].second = ans[u].second + dy[d] * len;
      dfs(dfs, v, u, d, len >> 1);
    }
  };
  dfs(dfs, 1, 0, -1, 1LL << 50);
  if (flag) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << ans[i].first << " " << ans[i].second << "\n";
    }
  } else {
    cout << "NO\n";
  }
}
