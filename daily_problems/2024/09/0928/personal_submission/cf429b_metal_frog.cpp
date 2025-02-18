const int N = 1007;
int n, m;
ll G[N][N];
ll f1[N][N], f2[N][N], g1[N][N], g2[N][N];

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> G[i][j];
    }
  }
  f1[0][0] = G[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i - 1 >= 0)
        f1[i][j] = max(f1[i][j], G[i][j] + f1[i - 1][j]);
      if (j - 1 >= 0)
        f1[i][j] = max(f1[i][j], G[i][j] + f1[i][j - 1]);
    }
  }
  g1[n - 1][0] = G[n - 1][0];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (i + 1 < n)
        g1[i][j] = max(g1[i][j], G[i][j] + g1[i + 1][j]);
      if (j - 1 >= 0)
        g1[i][j] = max(g1[i][j], G[i][j] + g1[i][j - 1]);
    }
  }
  f2[n - 1][m - 1] = G[n - 1][m - 1];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i + 1 < n)
        f2[i][j] = max(f2[i][j], G[i][j] + f2[i + 1][j]);
      if (j + 1 < m)
        f2[i][j] = max(f2[i][j], G[i][j] + f2[i][j + 1]);
    }
  }
  g2[0][m - 1] = G[0][m - 1];
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (i - 1 >= 0)
        g2[i][j] = max(g2[i][j], G[i][j] + g2[i - 1][j]);
      if (j + 1 < m)
        g2[i][j] = max(g2[i][j], G[i][j] + g2[i][j + 1]);
    }
  }
  ll ans = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      ans = max(ans, g1[i + 1][j] + g2[i - 1][j] + f1[i][j - 1] + f2[i][j + 1]);
      ans = max(ans, g1[i][j - 1] + g2[i][j + 1] + f1[i - 1][j] + f2[i + 1][j]);
    }
  }
  cout << ans << "\n";
}
