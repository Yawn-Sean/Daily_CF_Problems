int main() {
  int n; cin >> n;
  auto a = getv(n, 1);
  BIT<int> bit(n, 0, [&] (int a, int b) {
    return a + b;
  });
  i64 ans = 0;
  vector<pair<int, int>> vp;
  for (int i = 1; i <= n; i ++) if (a[i] > i)
    vp.emplace_back(i, -i),
    vp.emplace_back(min(a[i], n), i);
  int cur = 0;
  for (auto [u, b]: sorted(vp)) {
    while (cur != u)
      bit.apply(min(a[++ cur], n), 1);
    if (b < 0)
      ans -= cur - bit.query(-b - 1);
    else
      ans += cur - bit.query(b - 1);
  }
  printf("%lld\n", ans);
  return 0;
}
