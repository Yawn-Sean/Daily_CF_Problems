int main() {
  int n; string s; cin >> n >> s;
  vector<int> ans(n + 1);
  for (int d = 1; d <= n; d ++) if (n % d == 0) {
    vector<int> cnt(d);
    for (int i = 0; i < n; i ++)
      cnt[i % d] ^= (s[i] - '0');
    if (*max_element(ALL(cnt)) == 0)
      ans[d] = 1;
  }
  int c = 0;
  for (int i = 1; i <= n; i ++)
    c += ans[gcd(i, n)];
  printf("%d", c);
  return 0;
}
