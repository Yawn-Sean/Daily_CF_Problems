int main() {
  multiCase() {
    int n; string s, t;
    cin >> n >> s >> t;
    vector<pair<int, int>> vp;

    auto calc = [&] (int i, int j) {
      vp.emplace_back(i + 1, j + 1);
      swap(s[i], t[j]);
    };

    bool flg = true;
    for (int i = 0; i < n; i ++) if (s[i] != t[i]) {
      bool act = false;
      for (int j = i + 1; j < n; j ++) {
        if (t[j] == s[i])
          calc(j, j);
        if (s[j] == s[i]) {
          calc(j, i);
          act = true;
          break;
        }
      }
      if (!act) {
        flg = false;
        break;
      }
    }
    if (flg) {
      puts("Yes");
      printf("%d\n", (int)vp.size());
      for (auto [a, b]: vp)
        printf("%d %d\n", a, b);
    }
    else
      puts("No");
  }
  return 0;
}
