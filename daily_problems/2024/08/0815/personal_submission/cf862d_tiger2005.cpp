int main() {
  int n; scanf("%d", &n);
  string s(n, '0');
  auto ask = [&] () {
    printf("? %s\n", s.c_str());
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
  };
  int x = ask();
  s[0] = '1';
  int y = ask();
  int coef, pos0 = 0, pos1 = 0;
  if (x < y) {
    pos0 = 1;
    coef = 1;
  }
  else {
    pos1 = 1;
    coef = -1;
  }
  int l = 0, r = n - 1;
  while (l < r - 1) {
    int m = (l + r) >> 1;
    for (int i = 0; i < n; i ++)
      s[i] = "01"[i <= m];
    if (ask() - x == (m + 1) * coef)
      l = m;
    else
      r = m;
  }
  (pos0 == 0 ? pos0 : pos1) = r + 1;
  printf("! %d %d\n", pos0, pos1);
  return 0;
}
