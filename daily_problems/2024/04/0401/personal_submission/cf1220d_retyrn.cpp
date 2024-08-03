int n;

ll lowbit(ll x) {
    return x & -x;
}

void solve() {
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    map<ll, int> mp;
    for (auto x : a) {
        mp[lowbit(x)] += 1;
    }
    
    int mx = 0;
    ll val = -1;
    for (auto& [k, v] : mp) {
        if (v > mx) {
            mx = v;
            val = k;
        }
    }
    cout << n - mx << endl;
    for (int i = 0; i < n; i ++) {
        if (lowbit(a[i]) == val) continue;
        cout << a[i] << ' ';
    }
    cout << endl;
}