int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<array<int, 26>> ans(n + 1);
  for (int i = 0; i < n; i ++) {
    for (int c = 'a'; c <= 'z'; c ++) {
      int cnt = 0;
      for (int j = i; j < n; j ++) {
        cnt += (s[j] != c);
        ckmax(ans[cnt][c - 'a'], j - i + 1);
      }
    }
  }
  for (int i = 1; i <= n; i ++)
    for (int j = 0; j < 26; j ++)
      ckmax(ans[i][j], ans[i - 1][j]);
  multiCase() {
    auto [i, c] = reads<int, char>();
    printf("%d\n", ans[i][c - 'a']);
  }
  return 0;
}
