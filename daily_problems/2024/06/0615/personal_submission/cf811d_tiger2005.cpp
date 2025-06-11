tuple<int, int, char> dis[4] = {
  {0, 1, 'R'},
  {0, -1, 'L'},
  {1, 0, 'D'},
  {-1, 0, 'U'}
};

int main() {
  int n, m; cin >> n >> m;
  auto a = getv<string>(n);

  auto oppo = [&] (char d) {
    if (d == 'L' || d == 'R')
      return 'L' ^ 'R' ^ d;
    return 'U' ^ 'D' ^ d;
  };
  auto send = [&] (char d) {
    printf("%c\n", d);
    fflush(stdout);
    int x, y; cin >> x >> y;
    return pair<int, int>{x - 1, y - 1};
  };
  vector<vector<bool>> vis(n, vector<bool>(m));
  string final = "", cur = "";
  auto dfs = [&] (auto self, int l, int r) {
    if (l < 0 || l >= n || r < 0 || r >= m || vis[l][r] || a[l][r] == '*')
      return;
    vis[l][r] = true;
    if (a[l][r] == 'F') {
      final = cur;
      return;
    }
    for (auto [a, b, ch]: dis) {
      cur.push_back(ch);
      self(self, l + a, r + b);
      cur.pop_back();
    }
  };

  dfs(dfs, 0, 0);
  int T1 = -1, T2 = -1;
  pair<int, int> las{0, 0};
  for (auto ch: final) {
    if (ch == 'L' || ch == 'R') {
      if (T1 == 0)
        las = send(ch);
      else if (T1 == 1)
        las = send(oppo(ch));
      else {
        auto nw = send(ch);
        if (nw != las)
          T1 = 0, las = nw;
        else
          T1 = 1, las = send(oppo(ch));
      }
    }
    else {
      if (T2 == 0)
        las = send(ch);
      else if (T2 == 1)
        las = send(oppo(ch));
      else {
        auto nw = send(ch);
        if (nw != las)
          T2 = 0, las = nw;
        else
          T2 = 1, las = send(oppo(ch));
      }
    }
  }

  return 0;
}
