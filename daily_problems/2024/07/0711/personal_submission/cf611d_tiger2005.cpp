char ch[5010];
int pre[5010][5010];
Z dp[5010][5010], tag[5010][5010];
int main() {
  int n;
  cin >> n >> (ch + 1);
  for (int i = n; i >= 1; i --)
    for (int j = i + 1; j <= n; j ++)
      pre[i][j] = (ch[i] == ch[j] ? pre[i + 1][j + 1] + 1 : 0);
  auto check = [&] (int a, int b) {
    int len = b - a;
    if (len <= pre[a][b])
      return false;
    len = pre[a][b];
    return ch[a + len] < ch[b + len];
  };
  for (int i = 1; i <= n; i ++) {
    dp[i][1] ++;
    for (int j = 1; j <= i; j ++) {
      tag[i][j] += tag[i - 1][j];
      dp[i][j] += tag[i][j];
      int len = i - j + 1;
      if (ch[i + 1] == '0' || i + len > n)
        continue;
      if (check(j, i + 1))
        dp[i + len][i + 1] += dp[i][j];
      tag[i + len + 1][i + 1] += dp[i][j];
    }
  }
  Z ans = 0;
  for (int i = 1; i <= n; i ++)
    ans += dp[n][i];
  printf("%d", (int)ans);
  return 0;
}
