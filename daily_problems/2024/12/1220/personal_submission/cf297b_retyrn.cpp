int n, m, k;

void solve() {
    cin >> n >> m >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    for (int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        mp[x] --;
    }
    
    vector<pii> a(all(mp));
    
    // 从后往前 什么时候有大于了就可以
    ll cur = 0;
    for (int i = sz(a) - 1; i >= 0; i --) {
        cur += a[i].se;
        if (cur > 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}