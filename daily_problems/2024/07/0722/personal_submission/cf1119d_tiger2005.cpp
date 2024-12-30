int main() {
  int n; cin >> n;
  auto s = getv<i64>(n);
  int q; cin >> q;
  vector<pair<long long, int>> vp;
  for (auto [idx, val]: index(getv<i64, i64>(q))) {
    auto [l, r] = val;
    vp.emplace_back(r - l + 1, idx);
  }
  vector<long long> ansl(q);
  sort(s);
  for (int i = 1; i < n; i ++)
    vp.emplace_back(s[i] - s[i - 1], -1);

  long long ans = 0, cnt = n, t = 0;
  for (auto [d, op]: sorted(vp)) {
    ans += cnt * (d - t);
    t = d;
    if (op == -1)
      -- cnt;
    else
      ansl[op] = ans;
  }
  write(ansl, "%lld ");

  return 0;
}
