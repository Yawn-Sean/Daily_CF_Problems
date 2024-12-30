void solve() {
  int n, m;
  string s;
  cin >> n >> s >> m;
  for (int i = n - 1; i >= 0; i--) {
    prefixa[i] = (s[i] != 'b' ? prefixb[i + 1] + 1 : 0);
    prefixb[i] = (s[i] != 'a' ? prefixa[i + 1] + 1 : 0);
  }
  for (int i = 0; i < n; i++) {
    wildcard[i + 1] = wildcard[i] + (s[i] == '?');
  }
  for (int i = 0; i < n; i++) {
    if (dp[i] > dp[i + 1] ||
        (dp[i] == dp[i + 1] && change[i] < change[i + 1])) {
      dp[i + 1] = dp[i];
      change[i + 1] = change[i];
    }
    if (prefixa[i] >= m) {
      int newVal = dp[i] + 1,
          newChange = change[i] + wildcard[i + m] - wildcard[i];
      if (newVal > dp[i + m] ||
          (newVal == dp[i + m] && newChange < change[i + m])) {
        dp[i + m] = newVal;
        change[i + m] = newChange;
      }
    }
  }
  cout << change[n] << "\n";
}
