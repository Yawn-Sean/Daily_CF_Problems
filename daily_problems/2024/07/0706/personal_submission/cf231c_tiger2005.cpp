int main() {
  int n, k; cin >> n >> k;
  auto a = sorted(getv(n));
  int l = 0;
  pair<int, int> ans = {0, 0};
  long long cnt = 0;
  for (int r = 0; r < n; r ++) {
    while (cnt > k)
      cnt -= a[r] - a[l ++];
    ckmax(ans, {r - l + 1, - a[r]});
    if (r != n - 1)
      cnt += 1ll * (r - l + 1) * (a[r + 1] - a[r]);
  }
  printf("%d %d\n", ans.first, - ans.second);
  return 0;
}
