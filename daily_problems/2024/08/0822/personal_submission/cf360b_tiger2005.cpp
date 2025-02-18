int main() {
  int n, k; cin >> n >> k;
  i64 l = -1, r = 2e9 + 10;
  auto a = getv(n, 1);

  auto check = [&] (i64 x) {
    vector<int> dis(n + 1);
    for (int i = 1; i <= n; i ++)
      dis[i] = i - 1;
    for (int i = 1; i <= n; i ++)
      for (int j = i + 1; j <= n; j ++) if (abs(a[j] - a[i]) <= x * (j - i))
        ckmin(dis[j], dis[i] + j - i - 1);
    int mn = n + 1;
    for (int i = 1; i <= n; i ++)
      ckmin(mn, dis[i] + n - i);
    return mn <= k;
  };

  while (l < r - 1) {
    i64 m = (l + r) >> 1;
    if (check(m))
      r = m;
    else
      l = m;
  }
  printf("%lld\n", r);
  return 0;
}
