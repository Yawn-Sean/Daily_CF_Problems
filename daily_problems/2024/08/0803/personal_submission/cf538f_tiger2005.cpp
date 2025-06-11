int main() {
  int n; cin >> n;
  auto a = getv(n, 1);
  auto b = uniqued(sorted(a));
  for (auto &e: a)
    e = lower_bound(ALL(b), e) - b.begin() + 1;

  vector<tuple<int, int, int>> vt;
  vector<int> ans(n - 1);
  for (int i = 1; i <= n; i ++)
    for (int k = 1; k < n; k ++) 
      if (k * (i - 1) + 2 <= n)
        vt.emplace_back(k * (i - 1) + 1, k - 1, -a[i]),
        vt.emplace_back(min(k * i + 1, n), k - 1, a[i]);
      else
        break;
  int ptr = 0;
  BIT<int> bit(n, 0, [&] (int a, int b) {
    return a + b;
  });
  for (auto [p, b, op]: sorted(vt)) {
    while (ptr < p)
      bit.apply(a[++ ptr], 1);
    if (op < 0)
      ans[b] -= bit.query(-op - 1);
    else
      ans[b] += bit.query(op - 1);
  }
  write(ans, "%d ");
  return 0;
}
