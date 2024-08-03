int main() {
  int n, k, p; cin >> n >> k >> p;
  auto a = getv(n, 1);
  for (int i = 1; i <= n; i ++)
    a[i] = a[i] % p + a[i - 1];
  vector<int> dp(k);
  vector<int> idx(k);
  for (int i = 1; i < n; i ++)
    for (int j = k - 1; j > 0; j --) {
      int tmp = dp[j - 1] + (a[i] - a[idx[j - 1]]) % p;
      if (dp[j] < tmp)
        dp[j] = tmp, idx[j] = i;
    }
  printf("%d", dp[k - 1] + (a[n] - a[idx[k - 1]]) % p);
  return 0;
}
