int n;

void solve() {
    // 相当于换位两次
    cin >> n;
    vector<int> a(n);
    cin >> a;
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    if (n == 2) {
        cout << (a[0] <= a[1] ? "YES" : "NO") << endl;
        return;
    }
    
    map<int, int> mp;
    for (int i = 0; i < n; i ++) {
        mp[a[i]] = 0;
    }
    int idx = 1;
    for (auto& [k, v] : mp) {
        v = idx ++;
    }
    
    for (auto& x : a) {
        x = mp[x];
    }
    
    int m = sz(mp);
    if (m < n) {
        cout << "YES" << endl;
        return;
    }
    
    BIT<int> bit(m);
    ll res = 0;
    for (auto x : a) {
        res += bit.sum(x + 1, m);
        bit.add(x, 1);
    }
    cout << ((res & 1) ? "NO" : "YES") << endl;
}