struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1)
      s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1)
      res += s[pos - 1];
    return res;
  }
  int lower_bound(ll sum) { // min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0)
      return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= sz(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<pii> seq(n);
  vector<int> origin(n);
  for (int i = 0; i < n; i++) {
    cin >> seq[i].first;
    origin[i] = seq[i].first;
    seq[i].second = -i;
  }
  sort(all(seq));
  reverse(all(seq));
  FT fenwick(n + 10);
  int m;
  cin >> m;
  unordered_map<int, vector<pii>> query;
  vector<int> ans(m);
  vector<int> K;
  for (int i = 0; i < m; i++) {
    int k, pos;
    cin >> k >> pos;
    query[k].emplace_back(i, pos);
    K.emplace_back(k);
  }
  sort(all(K));
  K.erase(unique(all(K)), K.end());
  int cur = 0;
  for (int k : K) {
    while (cur < k) {
      auto [val, idx] = seq[cur];
      fenwick.update(-idx, 1);
      cur++;
    }
    for (auto [idx, pos] : query[k]) {
      int it = fenwick.lower_bound(pos);
      ans[idx] = origin[it];
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }
}
