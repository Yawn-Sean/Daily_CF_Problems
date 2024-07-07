int main() {
  int n; cin >> n;
  auto get = [&] (int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    return read<string>();
  };
  string s1 = "", s2 = "";
  int x = 1, y = 1;
  for (int i = 1; i < n; i ++) {
    if (get(x + 1, y, n, n) == "YES")
      ++ x, s1 += 'D';
    else
      ++ y, s1 += 'R';
  }
  int xx = n, yy = n;
  for (int i = 1; i < n; i ++) {
    if (yy - 1 >= y && get(1, 1, xx, yy - 1) == "YES")
      -- yy, s2 += 'R';
    else
      -- xx, s2 += 'D';
  }
  s1 += reversed(s2);
  printf("! %s\n", s1.c_str());
  return 0;
}
