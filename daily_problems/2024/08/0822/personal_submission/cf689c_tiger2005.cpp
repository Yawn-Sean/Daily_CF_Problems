int main() {
  i64 n; cin >> n;
  auto check = [&] (i64 q) {
    i64 res = 0;
    for (i64 i = 2; i * i * i <= q; i ++)
      res += q / (i * i * i);
    return res;
  };
  i64 l = 0, r = 8 * n + 1;
  while (l < r - 1) {
    i64 m = (l + r) >> 1;
    if (check(m) >= n)
      r = m;
    else
      l = m;
  }
  if (check(r) != n)
    r = -1;
  printf("%lld\n", r);
  return 0;
}
