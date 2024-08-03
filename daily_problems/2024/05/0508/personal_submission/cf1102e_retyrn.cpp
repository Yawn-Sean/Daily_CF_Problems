int n;

ll powmod (ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for(; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
void solve() {
    cin >> n;
    // 统计每个数的最左和最右 算出有多少块
    map<int, pii> mp;
    
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (mp.count(a[i])) mp[a[i]].se = i;
        else mp[a[i]] = mpr(i, i);
    }
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        int j = i, ed = mp[a[i]].se;
        while (j <= ed) {
            ed = max(ed, mp[a[j]].se);
            j ++;
        }
        i = j - 1;
        cnt ++;
    }
    cout << powmod(2, cnt - 1) << endl;
}