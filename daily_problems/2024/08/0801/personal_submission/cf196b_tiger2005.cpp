int dis[4][2] = {
  1, 0, 0, 1, -1, 0, 0, -1
};

int main() {
  int n, m; cin >> n >> m;
  auto v = getv<string>(n);
  vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(m, {-1e9, -1e9}));
  int x = 0, y = 0;
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      if (v[i][j] == 'S')
        x = i, y = j;
  auto dfs = [&] (auto self, int x, int y) -> void {
    int px = (x % n + n) % n, py = (y % m + m) % m;
    if (v[px][py] == '#')
      return;
    if (vis[px][py].first == -1e9)
      vis[px][py] = {x, y};
    else if (vis[px][py] != pair<int, int>{x, y}) {
      puts("Yes");
      exit(0);
    }
    else
      return;
    for (int d = 0; d < 4; d ++) {
      int xx = x + dis[d][0], yy = y + dis[d][1];
      self(self, xx, yy);
    }
  };
  dfs(dfs, x, y);
  puts("No");
  return 0;
}
