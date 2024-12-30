int main() {
  int n; cin >> n;
  auto v = getv(n, 1);
  vector<int> p(n + 1), dp(n + 1);
  for (int i = 1; i <= n; i ++)
    p[v[i]] = i;
  for (int i = n; i >= 1; i --) {
    int &val = dp[i];
    for (int j = p[i] % i; j <= n; j += i) if (j != 0 && j != p[i]) {
      if (v[j] > i && dp[v[j]] == 0)
        val = 1;
    }
  }
  for (int i = 1; i <= n; i ++)
    putchar("AB"[dp[v[i]] == 0]);
  return 0;
}
