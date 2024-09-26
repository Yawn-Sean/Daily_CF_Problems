void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  map<ll, int> vis;
  map<pii, int> v;
 
  ll ans = 0;
 
  for (int i = 0; i < n; i++) {
    int x, vx, vy;
    cin >> x >> vx >> vy;
 
    ans += vis[-1ll * a * vx + vy];
    ans -= v[{vx, vy}];
 
    vis[-1ll * a * vx + vy]++;
    v[{vx, vy}]++;
  }
  cout << ans * 2;
}
