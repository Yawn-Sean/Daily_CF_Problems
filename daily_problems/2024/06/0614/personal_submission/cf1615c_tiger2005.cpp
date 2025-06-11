int main() {
  multiCase() {
    int n; string s, t;
    cin >> n >> s >> t;
    auto check = [&] (int ty) {
      string res = t;
      for (auto &e: res)
        e ^= ty;
      int a = 0, b = 0;
      for (int i = 0; i < n; i ++) if (ty ^ (s[i] != t[i])) {
        if (s[i] == '0')
          ++ a;
        else
          ++ b;
      }
      return b == a + ty ? a + b : n + 1;
    };
    int ans = min(check(0), check(1));
    printf("%d\n", ans == n + 1 ? -1 : ans);
  }
}
