vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int main() {
  int n, m; string str;
  cin >> n >> m >> str;
  auto y = getv(m);

  auto v = z_function(str);
  for (int i = 1; i < m; i ++) {
    int dif = y[i] - y[i - 1];
    if (dif < (int)str.size() && v[dif] != (int)str.size() - dif)
      return puts("0"), 0;
  }

  int las = -1;
  Z ans = 1;
  for (auto e: y) {
    -- e;
    if (las < e - 1)
      ans *= Z(26).pow(e - las - 1);
    las = e + str.size() - 1;
  }
  ans *= Z(26).pow(n - las - 1);
  printf("%d", (int)ans);

  return 0;
}
