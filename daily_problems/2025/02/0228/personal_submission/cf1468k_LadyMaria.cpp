void solve() {
  string s;
  cin >> s;
  int x = 0, y = 0;
  set<PII> vis;

  for (auto c : s) {
    if (c == 'U')
      y++;
    else if (c == 'D')
      y--;
    else if (c == 'L')
      x--;
    else
      x++;
    if (x || y) vis.insert(PII(x, y));
  }

  auto check = [&](int obx, int oby) {
    int x = 0, y = 0;
    for (auto c : s) {
      int x1 = x, y1 = y;
      if (c == 'U')
        y++;
      else if (c == 'D')
        y--;
      else if (c == 'L')
        x--;
      else
        x++;
      if (PII(x, y) == PII(obx, oby)) {
        x = x1, y = y1;
      }
    }
    return PII(x, y) == PII(0, 0);
  };

  for (auto [x, y] : vis) {
    if (check(x, y)) {
      cout << x << ' ' << y << '\n';
      return;
    }
  }
  cout << "0 0\n";
}
