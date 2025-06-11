int main() {
  int n, k, x;
  cin >> n >> k >> x;
  i64 u = 1;
  while (k --)
    u *= x;
  auto a = getv<i64>(n);
  vector<i64> pre = a, suf = a;
  for (int i = 1; i < n; i ++)
    pre[i] |= pre[i - 1];
  for (int i = n - 2; i >= 0; i --)
    suf[i] |= suf[i + 1];
  i64 ans = 0;
  for (int i = 0; i < n; i ++) {
    i64 tmp = a[i] * u;
    if (i)
      tmp |= pre[i - 1];
    if (i != n - 1)
      tmp |= suf[i + 1];
    ckmax(ans, tmp);
  }
  printf("%lld", ans);
  return 0;
}
