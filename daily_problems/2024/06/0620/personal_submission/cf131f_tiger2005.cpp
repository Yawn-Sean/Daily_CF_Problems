pair<int, int> d[5] = {
  {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int main() {
  auto [n, m, k] = reads<int, int, int>();
  auto v = getv<string>(n);
  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 1; i < n - 1; i ++)
    for (int j = 1; j < m - 1; j ++) {
      bool flg = true;
      for (auto [x, y]: d)
        flg &= v[i + x][j + y] == '1';
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + flg;
    }
  // [a, b] * [c, d]
  auto get = [&] (int a, int b, int c, int d) {
    if (b - a <= 1 || d - c <= 1)
      return 0;
    return arr[b - 1][d - 1] - arr[a][d - 1] - arr[b - 1][c] + arr[a][c];
  };
  long long ans = 0;
  for (int i = 0; i < n; i ++)
    for (int j = i + 2; j < n; j ++) {
      int ptr = 0;
      for (int t = 0; t < m; t ++) {
        while (ptr != m && get(i, j, t, ptr) < k)
          ++ ptr;
        ans += m - ptr;
      }
    }
  printf("%lld", ans);
  return 0;
}
