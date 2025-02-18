void solve() {
  int n;
  ll x1, x2;
  cin >> n >> x1 >> x2;
  vector<pair<ll, ll>> pt;
  for (int i = 0; i < n; i++) {
    ll k, b;
    cin >> k >> b;
    pt.emplace_back(make_pair(k * x1 + b, k * x2 + b));
  }
  sort(all(pt));
  set<ll> y2;
  for (int i = 0; i < n; i++) {
    if (y2.size() != 0 && y2.upper_bound(pt[i].second) != y2.end()) {
      cout << "YES\n";
      return;
    } else {
      y2.insert(pt[i].second);
    }
  }
  cout << "NO\n";
}
