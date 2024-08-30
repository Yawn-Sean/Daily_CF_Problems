int main() {
  int n; scanf("%d", &n);
  if (n % 4)
    return puts("! -1"), 0;
  // ask i minus opposite
  auto ask = [&] (int x) {
    int a, b;
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &a);
    printf("? %d\n", x + n / 2);
    fflush(stdout);
    scanf("%d", &b);
    return a - b;
  };
  int u = ask(1);
  if (u % 2)
    return puts("! -1"), 0;
  u /= 2;
  if (u == 0)
    return puts("! 1"), 0;

  int l = 1, r = n / 2 + 1;
  while (1) {
    int m = (l + r) >> 1;
    int uu = ask(m) / 2;
    if (uu == 0)
      return printf("! %d\n", m), 0;
    if (uu * u > 0)
      l = m;
    else
      r = m;
  }
  return 0;
}
