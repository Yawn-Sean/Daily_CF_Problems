int main() {
  int t; cin >> t;
  while (t --) {
    int n; cin >> n;
    vector<string> vec(n);
    for (auto &e: vec)
      cin >> e;
    vector<int> ans(n);
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < n; j ++) if (vec[i][j] == '1')
        ++ ans[(j - i + n) % n];
    int x = 0, rans = n * n;
    for (auto e: ans)
      x += e;
    for (auto e: ans)
      rans = min(rans, x + n - 2 * e);
    printf("%d\n", rans);
  }
  return 0;
}
