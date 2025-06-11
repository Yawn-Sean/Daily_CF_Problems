int main() {
  auto [n, k] = reads<int, int>();
  if (k == 1)
    return puts("2"), 0;
  vector<vector<Z>> f(k + 1, vector<Z>(4)), g;
  f[1][0] = f[1][3] = f[2][1] = f[2][2] = 1;
  for (int i = 2; i <= n; i ++) {
    g.assign(k + 1, vector<Z>(4, 0));
    for (int l = 0; l < 4; l ++)
      for (int r = 0; r < 4; r ++) {
        int ans = ((l & 1) != (r & 1)) + ((l / 2) != (r / 2));
        if (r == 0 || r == 3)
          ans = max(ans - 1, 0);
        for (int x = k - ans; x >= 0; x --)
          g[x + ans][r] += f[x][l];
      }
    swap(f, g);
  }
  printf("%d", (int)accumulate(ALL(f[k]), Z(0)));
  return 0;
}
