int main() {
  auto divisor = [&] (int x) {
    vector<int> res;
    for (int i = 1; i * i <= x; i ++) if (x % i == 0) {
      res.push_back(i);
      if (i * i != x)
        res.push_back(x / i);
    }
    return res;
  };

  int n; cin >> n;
  vector<int> las(1e5 + 1, -1);
  for (auto [idx, val]: index(getv<int, int>(n))) {
    auto [x, y] = val;
    int ans = 0;
    for (auto e: divisor(x)) {
      ans += las[e] < idx - y;
      las[e] = idx;
    }
    printf("%d\n", ans);
  }

  return 0;
}
