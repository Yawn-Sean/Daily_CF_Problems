int main() {
  auto calc = [&] (int x) {
    return (x - 1) * x / 2 + 1 + (x & 1 ? 0 : (x - 2) / 2);
  };
  int n, m; cin >> n >> m;
  vector<int> v;
  for (auto [a, b]: getv<int, int>(m))
    v.push_back(b);
  sort(v); reverse(v);
  long long ans = 0;
  for (int i = 1; i <= m; i ++) {
    if (calc(i) > n)
      break;
    ans += v[i - 1];
  }
  printf("%lld\n", ans);
  return 0;
}
