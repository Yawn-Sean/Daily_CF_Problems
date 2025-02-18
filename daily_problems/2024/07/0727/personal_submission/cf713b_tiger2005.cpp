int main() {
  int n = read();

  vector<int> v;
  for (int i = 1; i <= n; i ++)
    v.push_back(i);

  auto get = [&] (int a, int b, int c, int d, bool rev) {
    if (rev)
      swap(a, b), swap(c, d);
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    return read();
  };

  auto bs = [&] (int l, int r, auto pred) { return partition_point(l - 1 + v.begin(), r + v.begin(), pred); };

  auto get_one = [&] (int a, int b, int c, int d, bool rev) -> tuple<int, int, int, int> {
    a = *(bs(a, c, [&] (int x) { return get(x, b, c, d, rev) == 1; }) - 1);
    b = *(bs(b, d, [&] (int x) { return get(a, x, c, d, rev) == 1; }) - 1);
    c = *bs(a, c, [&] (int x) { return get(a, b, x, d, rev) == 0; });
    d = *bs(b, d, [&] (int x) { return get(a, b, c, x, rev) == 0; });
    return {a, b, c, d};
  };

  auto calc = [&] (bool rev) -> bool {
    int p = *bs(1, n, [&] (int x) {
      return get(1, 1, x, n, rev) == 0;
    });
    if (get(1, 1, p, n, rev) != 1 || get(p + 1, 1, n, n, rev) != 1)
      return false;
    auto [a, b, c, d] = get_one(1, 1, p, n, rev);
    auto [e, f, g, h] = get_one(p + 1, 1, n, n, rev);
    if (rev)
      swap(a, b), swap(c, d), swap(e, f), swap(g, h);
    printf("! %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
    return true;
  };

  if (!calc(false))
    calc(true);
  return 0;
}
