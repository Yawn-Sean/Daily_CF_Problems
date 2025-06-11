int main() {
  int n, m; cin >> n >> m;
  if (m == 1ll * n * (n - 1) / 2)
    return puts("NO"), 0;
  puts("YES");
  set<pair<int, int>> st;
  for (auto [a, b]: getv<int, int>(m))
    st.insert(minmax(a, b));
  for (int i = 1; i <= n; i ++)
    for (int j = 1; j < i; j ++) if (!st.count({j, i})) {
      vector<int> v(n + 1);
      v[i] = n - 1, v[j] = n;
      int cnt = 0;
      for (int k = 1; k <= n; k ++) if (!v[k])
        v[k] = ++ cnt;
      for (int k = 1; k <= n; k ++)
        printf("%d ", v[k]);
      puts("");
      v[i] = n;
      for (int k = 1; k <= n; k ++)
        printf("%d ", v[k]);
      puts("");
      return 0;
    }
  return 0;
}
