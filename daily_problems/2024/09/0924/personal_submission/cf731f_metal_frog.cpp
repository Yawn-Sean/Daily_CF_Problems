const int N = 200000 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(all(a));
  FT fenwick(N);
  for (int i = 0; i < n; i++) {
    fenwick.update(a[i], 1);
  }
  a.erase(unique(all(a)), a.end());
  ll ans = 0;
  for (int i = 0; i < a.size(); i++) {
    ll sum = 0;
    for (int k = 1; k * a[i] <= N; k++) {
      ll cnt = fenwick.query(min(N, (k + 1) * a[i])) - fenwick.query(k * a[i]);
      sum += ll(k * a[i]) * cnt;
    }
    ans = max(ans, sum);
  }
  cout << ans << "\n";
}
