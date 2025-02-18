void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    unordered_map<ll, ll> hashmap, counter;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        counter[a[i]] += 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        hashmap[a[i]] += b[i];
    }
    ll ans = 0;
    unordered_set<ll> picked;
    for (auto& [val, cnt] : counter) {
        if (cnt >= 2) {
            ans += hashmap[val];
            picked.insert(val);
        }
    }
    for (int i = 0; i < n; i++) {
        if (picked.find(a[i]) == picked.end()) {
            for (ll x : picked) {
                if ((a[i] & x) == a[i]) {
                    ans += b[i];
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}
 
