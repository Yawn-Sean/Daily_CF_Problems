int main() {
  auto getp = [&] () {
    return read<pair<double, double>>();
  };
  auto a = getp();
  auto b = getp();
  auto t = getp();
  auto dis = [&] (pair<double, double> a, pair<double, double> b) {
    return hypot(a.first - b.first, a.second - b.second);
  };
  vector<double> dp(4, 1e10);
  int n; cin >> n;
  double l = 0; dp[0] = 0;
  for (auto e: getv<pair<double, double>>(n)) {
    l += 2 * dis(t, e);
    vector<double> tmp(4, 1e10);
    for (int i = 0; i < 4; i ++)
      for (int j = i; j < 4; j ++) if ((i & j) == i) {
        int u = i ^ j;
        if (u == 3)
          continue;
        double coef = 0;
        if (u == 1)
          coef = dis(a, e) - dis(t, e);
        if (u == 2)
          coef = dis(b, e) - dis(t, e);
        ckmin(tmp[j], dp[i] + coef);
      }
    dp = tmp;
  }
  dp[0] = 1e10;
  printf("%.12f", *min_element(ALL(dp)) + l);
  return 0;
}
