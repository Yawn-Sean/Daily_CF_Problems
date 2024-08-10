int main() {
  int n, q; string s;
  cin >> n >> q >> s;
  int ans = 0;
  for (int i = 1; i < n; i ++)
    ans += (s[i] == '.' && s[i - 1] == '.');

  auto eval = [&] (int pos) {
    if (s[pos] != '.')
      return 0;
    int res = 0;
    if (pos != 0)
      res += s[pos - 1] == '.';
    if (pos != n - 1)
      res += s[pos + 1] == '.';
    return res;
  };

  while (q --) {
    int x; char ch;
    cin >> x >> ch; -- x;
    ans -= eval(x);
    ans += eval((s[x] = ch, x));
    printf("%d\n", ans);
  }
  return 0;
}
