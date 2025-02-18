int main() {
  int n, m; cin >> n >> m;
  auto v = getv<pair<int, int>>(m);
  for (auto &[a, b]: v)
    tie(a, b) = minmax(a % n, b % n);
  sort(v);
  auto check = [&] (int x) {
    auto w = v;
    for (auto &[a, b]: w)
      tie(a, b) = minmax((a + x) % n, (b + x) % n);
    return v == sorted(w);
  };
  int nn = n;
  for (int i = 2; i <= nn; i ++) if (nn % i == 0) {
    while (nn % i == 0)
      nn /= i;
    if (check(n / i))
      return puts("Yes"), 0;
  }
  puts("No");
  return 0;
}
