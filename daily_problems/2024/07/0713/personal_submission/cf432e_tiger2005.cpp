int main() {
  int n, m; cin >> n >> m;
  vector<string> vec(n, string(m, '.'));
  auto draw = [&] (int a, int b) {
    int h = 1;
    
    auto check = [&] (int x, int y, char addi = '\0') -> char {
      if (x >= n || y >= m)
        return ' ';
      vector<bool> app(4);
      if (x && vec[x - 1][y] != '.')
        app[vec[x - 1][y] - 'A'] = true;
      if (y && vec[x][y - 1] != '.')
        app[vec[x][y - 1] - 'A'] = true;
      if (x != n - 1 && vec[x + 1][y] != '.')
        app[vec[x + 1][y] - 'A'] = true;
      if (y != m - 1 && vec[x][y + 1] != '.')
        app[vec[x][y + 1] - 'A'] = true;

      if (addi != '\0')
        return !app[addi - 'A'] && (vec[x][y] == '.');

      char ch = 0;
      while (app[ch])
        ++ ch;
      return ch + 'A';
    };

    char ch = check(a, b);
    while (1) {
      bool flg = check(a, b + h) >= ch && a + h < n;
      for (int i = 0; i <= h && flg; i ++)
        flg &= check(a + h, b + i, ch) && check(a + i, b + h, ch);
      if (!flg)
        break;
      ++ h;
    }

    for (int i = a; i < a + h; i ++)
      for (int j = b; j < b + h; j ++) {
        vec[i][j] = ch;
      }
  };

  while (1) {
    bool flg = false;
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j ++) {
        if (vec[i][j] != '.')
          continue;
        flg = true;
        draw(i, j);
      }
    if (!flg)
      break;
  }
  for (auto e: vec)
    cout << e << endl;
  return 0;
}
