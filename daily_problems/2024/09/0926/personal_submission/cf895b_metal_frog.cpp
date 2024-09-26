void solve() {
  int n, x, k;
  cin >> n >> x >> k;
  vector<int> a(n);
  map<int, ll> counter, counter2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    counter2[a[i]]++;
  }
  ll ans = 0;
  for (auto &[val, cnt] : counter2) {
    int level = val / x;
    if (val % x != 0)
      level++;
    counter[level] += cnt;
    if (k == 0) {
      if (val % x != 0) {
        ll num = counter[val / x + 1] - counter2[(val / x) * x];
        ans += cnt * num;
      }
    } else {
      int key = val / x - k + 1;
      ans += counter[key] * cnt;
    }
  }
  cout << ans << "\n";
}
