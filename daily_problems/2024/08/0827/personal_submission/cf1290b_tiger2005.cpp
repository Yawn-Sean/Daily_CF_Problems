int pre[200010][26];

int main() {
  string s; cin >> s;
  int n = s.size();
  for (int i = 1; i <= n; i ++)
    memcpy(pre[i], pre[i - 1], 4 * 26),
    ++ pre[i][s[i - 1] - 'a'];

  multiCase() {
    int l, r; cin >> l >> r; -- l, -- r;
    int cnt = 0;
    for (int i = 0; i < 26; i ++)
      cnt += pre[r + 1][i] != pre[l][i];
    Yes(l == r || cnt > 2 || s[l] != s[r], "\n");
  }
  return 0;
}
