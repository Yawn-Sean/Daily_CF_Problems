int main() {
  int n; cin >> n;
  auto w = getv<i64>(n, 1);
  int q; cin >> q;
  vector<i64> ansl(q);
  vector<vector<pair<int, int>>> vp(n + 1);
  for (auto [idx, val]: index(getv<int, int>(q))) {
    auto [a, b] = val;
    vp[b].emplace_back(a, idx);
  }
  for (int i = 1; i <= n; i ++) {
    if (i <= sqrt(n)) {
      auto vec = w;
      for (int j = n; j > i; j --)
        vec[j - i] += vec[j];
      for (auto [st, idx]: vp[i])
        ansl[idx] = vec[st];
    }
    else {
      for (auto [st, idx]: vp[i]) {
        i64 ans = 0;
        while (st <= n)
          ans += w[st], st += i;
        ansl[idx] = ans;
      }
    }
  }
  write(ansl, "%lld\n");
  return 0;
}
