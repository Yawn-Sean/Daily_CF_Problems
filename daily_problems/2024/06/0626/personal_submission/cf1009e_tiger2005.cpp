int main() {
  int n; cin >> n;
  auto a = getv(n, 1);
  Z ans = 0;
  for (int i = 1; i <= n; i ++)
    ans += (Z(2).pow(n - i - 1) * (n - i + 2)) * a[i];
  printf("%d", (int)ans);
  return 0;
}
