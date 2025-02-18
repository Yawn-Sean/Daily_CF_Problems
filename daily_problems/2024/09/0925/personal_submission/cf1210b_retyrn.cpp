int n;

void solve() {
    cin >> n;
    vector<ll> a(n);
    vector<int> b(n);
    cin >> a >> b;
    
    map<ll, int> mp;
    for (int i = 0; i < n; i ++) {
        mp[a[i]] += 1;
    }
    vector<int> st(n, false);
    
    ll res = 0;
    
    for (auto [k, v] : mp) {
        if (v > 1) {
            for (int i = 0; i < n; i ++) {
                if (!st[i] and (a[i] & k) == a[i]) {
                    st[i] = true;
                    res += b[i];
                }
            }
        }
    }
    cout << res << endl;
}