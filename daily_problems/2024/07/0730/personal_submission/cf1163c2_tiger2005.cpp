int main() {
  int n; cin >> n;
  auto v = getv<int, int>(n);

  i64 ans = 0, sm = 0;
  map<pair<int, int>, int> st;
  vector<set<pair<int, int>>> vs(n);

  for (int i = 0; i < n; i ++)
    for (int j = 0; j < i; j ++) {
      auto [x1, y1] = v[i];
      auto [x2, y2] = v[j];
      x2 -= x1, y2 -= y1;
      int g = gcd(x2, y2);
      x2 /= g, y2 /= g;
      if (x2 == 0)
        y2 = abs(y2);
      else if (x2 < 0)
        x2 *= -1, y2 *= -1;

      vs[i].insert({x2, y2});
      if (vs[j].count({x2, y2}))
        continue;
      vs[j].insert({x2, y2});
      ans += sm - st[{x2, y2}];
      ++ st[{x2, y2}];
      ++ sm;
    }
  printf("%lld", ans);
  return 0;
}
