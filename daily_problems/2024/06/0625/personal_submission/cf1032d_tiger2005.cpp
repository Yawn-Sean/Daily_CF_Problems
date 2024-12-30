int main() {
  auto [a, b, c, x1, y1, x2, y2] = read<array<f64, 7>>();
  f64 ans = abs(x2 - x1) + abs(y2 - y1);
  auto get = [&] (int x, int y) -> vector<pair<f64, f64>> {
    vector<pair<f64, f64>> res;
    if (a != 0)
      res.emplace_back((- c - b * y) / a, y);
    if (b != 0)
      res.emplace_back(x, (- c - a * x) / b);
    return res;
  };
  auto dis = [&] (pair<f64, f64> a, pair<f64, f64> b) {
    return hypot(
      a.first - b.first,
      a.second - b.second
    );
  };
  for (auto e1: get(x1, y1))
    for (auto e2: get(x2, y2))
      ans = min(ans, dis({x1, y1}, e1) + dis(e1, e2) + dis(e2, {x2, y2}));
  printf("%.12f", ans);
  return 0;
}
