void solve() {
  int n;
  cin >> n;
  vector<pii> customer;
  for (int i = 0; i < n; i++) {
    int c, p;
    cin >> c >> p;
    customer.emplace_back(c, p);
  }
  int k;
  cin >> k;
  vector<pii> r;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    r.emplace_back(x, i + 1);
  }
  sort(all(r));
  vector<pii> ans;
  vector<int> vis(n);
  int total = 0;
  for (int i = 0; i < k; i++) {
    int match = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && customer[j].first <= r[i].first) {
        if (match == -1 || customer[match].second < customer[j].second) {
          match = j;
        }
      }
    }
    if (match != -1) {
      vis[match] = 1;
      ans.emplace_back(match + 1, r[i].second);
      total += customer[match].second;
    }
  }
  cout << sz(ans) << " " << total << "\n";
  for (auto [cus, table] : ans) {
    cout << cus << " " << table << "\n";
  }
}
