int main() {
  int n, k; cin >> n >> k;
  auto a = getv(n, 1);
  vector<long long> f(n + 1, 1), g;
  f[0] = 0;
  for (int i = 1; i <= k; i ++) {
    g.assign(n + 1, 0);
    BIT<long long> bit(n, 0, [&] (auto a, auto b) {
      return a + b;
    });
    for (int j = 1; j <= n; j ++) {
      g[j] = bit.query(a[j] - 1);
      bit.apply(a[j], f[j]);
    }
    f.swap(g);
  }
  printf("%lld\n", accumulate(ALL(f), 0ll));
  return 0;
}
