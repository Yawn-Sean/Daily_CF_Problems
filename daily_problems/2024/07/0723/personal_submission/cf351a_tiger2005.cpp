int main() {
  int n; cin >> n;
  auto v = getv<double>(2 * n);
  vector<int> a;
  for (auto e: v)
    a.push_back((int)round(e * 1000) % 1000);
  int ans = 1e9, cnt = 0, sum = 0;
  for (auto e: a)
    cnt += e == 0, sum += e;
  for (int i = max(0, n - cnt); i <= min(n, 2 * n - cnt); i ++)
    ans = min(ans, abs(1000 * i - sum));
  printf("%.3lf\n", ans / 1000.0);
  return 0;
}
