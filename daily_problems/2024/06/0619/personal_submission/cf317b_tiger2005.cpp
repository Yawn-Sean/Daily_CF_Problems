int d[210][210];

int main() {
  int n, q; cin >> n >> q;
  d[100][100] = n;
  while (1) {
    bool flg = false;
    for (int i = 0; i <= 200; i ++)
      for (int j = 0; j <= 200; j ++) if (d[i][j] >= 4) {
        int w = d[i][j] / 4;
        d[i][j] %= 4;
        d[i][j - 1] += w;
        d[i][j + 1] += w;
        d[i - 1][j] += w;
        d[i + 1][j] += w;
        flg = true;
      }
    if (!flg)
      break;
  }
  for (auto [x, y]: getv<pair<int, int>>(q)) {
    x += 100, y += 100;
    if (x < 0 || x > 200 || y < 0 || y > 200)
      puts("0");
    else
      printf("%d\n", d[x][y]);
  }
}
