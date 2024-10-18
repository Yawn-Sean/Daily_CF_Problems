int main() {
  int n, m; cin >> n >> m;
  int ans = n;
  for (auto [a, b]: getv<int, int>(m))
    ans = min(ans, b - a + 1);
  printf("%d\n", ans);
  for (int i = 0; i < n; i ++)
    printf("%d ", i % ans);
  return 0;
}
