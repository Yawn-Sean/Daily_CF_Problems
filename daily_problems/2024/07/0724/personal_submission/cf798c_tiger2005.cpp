int main() {
  puts("YES");
  int n; cin >> n;
  auto v = getv(n);
  int a = 0;
  for (auto e: v)
    a = gcd(a, e);
  if (a != 1)
    return puts("0"), 0;
  int cnt = 0, ans = 0;
  for (auto e: v)
    if (e & 1)
      ++ cnt;
    else
      ans += cnt / 2 + (cnt & 1 ? 2 : 0), cnt = 0;
  printf("%d", ans += cnt / 2 + (cnt & 1 ? 2 : 0));
  return 0;
}
