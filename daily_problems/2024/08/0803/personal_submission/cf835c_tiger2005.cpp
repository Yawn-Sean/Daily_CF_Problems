int pre[11][110][110];
int n, q, c;
int main() {
  cin >> n >> q >> c;
  for (auto [x, y, b]: getv<int, int, int>(n))
    pre[b][x][y] ++;
  for (int p = 0; p <= c; p ++)
    for (int i = 1; i <= 100; i ++)
      for (int j = 1; j <= 100; j ++)
        pre[p][i][j] += pre[p][i - 1][j] + pre[p][i][j - 1] - pre[p][i - 1][j - 1];

  for (auto [t, x1, y1, x2, y2]: getv<array<int, 5>>(q)) {
    int ans = 0;
    for (int i = 0; i <= c; i ++)
      ans += (pre[i][x2][y2] - pre[i][x1 - 1][y2] - pre[i][x2][y1 - 1] + pre[i][x1 - 1][y1 - 1]) * ((i + t) % (c + 1));
    printf("%d\n", ans);
  }
  return 0;
}
