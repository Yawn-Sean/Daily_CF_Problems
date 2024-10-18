i64 dp[5000010];

int main() {
  int t, l, r; cin >> t >> l >> r;
  memset(dp, 0x3f, sizeof dp);
  dp[1] = 0;
  for (int i = 1; i <= r; i ++)
    for (int j = 2 * i; j <= r; j += i)
      ckmin(dp[j], dp[i] + 1ll * j * (j/i - 1) / 2);
  Z ans = 0;
  for (int i = r; i >= l; i --)
    ans = ans * t + dp[i];
  printf("%d\n", (int)ans);
  return 0;
}
