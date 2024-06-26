int main() {
  int n; cin >> n;
  vector<int> v;
  long long ans = 0;
  for (auto [x, y]: getv<int, int>(n)) {
    ans += 1ll * y * n - x;
    v.push_back(x - y);
  }
  sort(v); reverse(v);
  for (int i = 0; i < n; i ++)
    ans += 1ll * v[i] * (i + 1);
  printf("%lld", ans);
}
