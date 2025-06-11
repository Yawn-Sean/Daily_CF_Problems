int main() {
  auto a = getv<pair<int, int>>(4);
  auto b = getv<pair<int, int>>(4);

  auto check = [&] () -> bool {
    vector<int> X, Y;
    for (auto [x, y]: a)
      X.push_back(x), Y.push_back(y);
    int x0 = *min_element(ALL(X));
    int x1 = *max_element(ALL(X));
    int y0 = *min_element(ALL(Y));
    int y1 = *max_element(ALL(Y));

    auto in = [&] (int x, int y) {
      return x >= x0 && x <= x1 && y >= y0 && y <= y1;
    };

    int xx = 0, yy = 0;

    for (auto [x, y]: b) {
      xx += x, yy += y;
      if (in(x, y))
        return true;
    }
    return in(xx / 4, yy / 4);
  };

  bool flg = check();
  swap(a, b);
  for (auto &[x, y]: a)
    tie(x, y) = tuple{x + y, x - y};
  for (auto &[x, y]: b)
    tie(x, y) = tuple{x + y, x - y};
  YES(flg | check());
  return 0;
}
