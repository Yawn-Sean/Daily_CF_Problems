int main() {
  int n; cin >> n;
  auto a = getv(n, 1);
  for (int i = 1; i <= n; i ++)
    a[i] += a[i - 1];
  i64 dp = 0, mx = a[n];
  for (int i = n - 1; i >= 1; i --) {
    dp = mx;
    ckmax(mx, a[i] - dp);
  }
  printf("%lld\n", dp);
  return 0;
}
