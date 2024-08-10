int main() {
  multiCase() {
    auto [n, k, s] = reads<int, int, string>();
    auto id = [&] (char ch) {
      if (ch == 'R')
        return 0;
      if (ch == 'G')
        return 1;
      return 2;
    };
    int ans = n;
    for (int st = 0; st < 3; st ++) {
      int cur = st;
      vector<int> col(n + 1);
      for (int i = 1; i <= n; i ++) {
        col[i] = col[i - 1] + (id(s[i - 1]) != cur);
        cur = (cur + 1) % 3;
      }
      for (int i = k; i <= n; i ++)
        ans = min(ans, col[i] - col[i - k]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
