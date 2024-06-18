int dp[26][26];

int main() {
  auto [a, b, m] = reads<string, string, int>();
  for (auto [s, t, v]: getv<char, char, int>(m))
    dp[s - 'a'][t - 'a'] = min(dp[s - 'a'][t - 'a'], v);
  if (a.size() != b.size())
    return puts("-1"), 0;
  for (int i = 0; i < 26; i ++)
    for (int j = 0; j < 26; j ++) if (i != j)
      dp[i][j] = 1e6;
  for (int k = 0; k < 26; k ++)
    for (int i = 0; i < 26; i ++)
      for (int j = 0; j < 26; j ++)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  int ans = 0;
  for (int i = 0; i < (int)a.size(); i ++) {
    char x = a[i] - 'a', y = b[i] - 'a';
    int mx = 1e6, ch = 0;
    for (int j = 0; j < 26; j ++) {
      int q = dp[(int)x][j] + dp[(int)y][j];
      if (q < mx)
        mx = q, ch = j + 'a';
    }
    if (mx == 1e6)
      return puts("-1"), 0;
    a[i] = ch;
    ans += mx;
  }
  cout << ans << endl << a;
  return 0;
}
