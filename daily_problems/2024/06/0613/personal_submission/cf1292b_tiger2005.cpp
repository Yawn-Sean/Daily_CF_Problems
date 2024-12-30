int main() {
  vector<pair<long long, long long>> points;
  points.push_back(read<pair<long long, long long>>());
  int a, b; long long c, d; cin >> a >> b >> c >> d;
  long long x, y, t;
  cin >> x >> y >> t;
  while (1) {
    auto [p, q] = points.back();
    p = a * p + c;
    q = b * q + d;
    if (p + q > x + y + t)
      break;
    points.emplace_back(p, q);
  }

  auto dist = [&] (pair<long long, long long> p1, pair<long long, long long> p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    return abs(x1 - x2) + abs(y1 - y2);
  };

  int ans = 0;
  for (int i = 0; i < (int)points.size(); i ++) {
    long long X = x, Y = y;
    long long T = t;
    int tmp = 0;
    for (int j = i; j >= 0; j --) {
      if ((T -= dist({X, Y}, points[j])) >= 0) {
        tie(X, Y) = points[j];
        ++ tmp;
      }
    }
    if (T >= 0)
      for (int j = i + 1; j < (int)points.size(); j ++) {
        if ((T -= dist({X, Y}, points[j])) >= 0) {
          tie(X, Y) = points[j];
          ++ tmp;
        }
      }
    ans = max(ans, tmp);
  }
  printf("%d", ans);
  return 0;
}
