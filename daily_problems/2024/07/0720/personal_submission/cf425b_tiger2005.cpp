int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> a;
  for (int i = 0; i < n; i ++)
    a.push_back(getv(m));
  int ans = k + 1;
  if (n <= k) {
    // | mode - mask
    for (int i = 0; i < (1 << n); i ++) {
      int cnt = 0;
      for (int y = 0; y < m; y ++) {
        int tmp = 0;
        for (int x = 0; x < n; x ++)
          tmp += (a[x][y] != ((i >> x) & 1));
        cnt += min(tmp, n - tmp);
      }
      ans = min(ans, cnt);
    }
  }
  else {
    // - mode - template
    for (int q = 0; q < n; q ++) {
      int cnt = 0;
      for (int x = 0; x < n; x ++) {
        int tmp = 0;        
        for (int y = 0; y < m; y ++)
          tmp += (a[x][y] != a[q][y]);
        cnt += min(tmp, m - tmp);
      }
      ans = min(ans, cnt);
    }
  }

  printf("%d\n", ans > k ? -1 : ans);
  return 0;
}
