int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a = sorted(getv(n));
  vector<vector<int>> selects(k + 1);
  for (auto e: a)
    for (int i = 1; i <= k; i ++)
      selects[i].push_back(e * i);

  multiCase() {
    int x; cin >> x;
    int ans = k + 1;
    for (int i = 1; i <= k; i ++) {
      for (auto v: selects[i]) {
        if (v > x)
          break;
        if (v == x) {
          ans = min(ans, i);
          break;
        }
        for (int j = 1; j <= k - i; j ++) {
          auto ptr = lower_bound(ALL(selects[j]), x - v);
          if (ptr != selects[j].end() && *ptr == x - v)
            ans = min(ans, i + j);
        }
      }
    }
    printf("%d\n", (ans == k + 1) ? -1 : ans);
  }
  return 0;
}
