int main() {
  int n, k; cin >> n >> k;
  Binom_facts bf(n);
  vector<pair<int, int>> vp;
  for (auto [l, r]: getv<int, int>(n))
    vp.emplace_back(l, 1),
    vp.emplace_back(r + 1, -1);

  Z ans = 0;
  int las = -1e9 - 10, cur = 0;
  for (auto [a, b]: sorted(vp)) {
    if (las != -1e9 - 10)
      ans += bf.get(cur, k) * (a - las);
    las = a; cur += b;
  }
  printf("%d\n", (int)ans);
  return 0;
}
