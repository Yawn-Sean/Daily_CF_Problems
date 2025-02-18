int di[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  int n, m, p; cin >> n >> m >> p;
  auto s = getv(p, 1);
  auto v = getv<string>(n);
  vector<int> ans(p + 1);
  vector<vector<pair<int, int>>> bnd(p + 1);

  auto check = [&] (int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && v[x][y] == '.';
  };

  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++) if (v[i][j] >= '1' && v[i][j] <= '9') {
      int id = v[i][j] - '0';
      ++ ans[id];
      bnd[id].emplace_back(i, j);
    }

  while (1) {
    bool flg = false;
    for (int i = 1; i <= p; i ++) if (!bnd[i].empty()) {
      flg = true;
      for (int t = 1; t <= s[i]; t ++) {
        if (bnd[i].empty())
          break;
        vector<pair<int, int>> nxt;
        for (auto [x, y]: bnd[i]) {
          for (int d = 0; d < 4; d ++) {
            int xx = x + di[d][0], yy = y + di[d][1];
            if (check(xx, yy))
              ++ ans[i], nxt.emplace_back(xx, yy), v[xx][yy] = '0' + i;
          }
        }
        bnd[i] = nxt;
      }
    }

    if (!flg)
      break;
  }

  ans.erase(ans.begin());
  write(ans, "%d ");
  return 0;
}
