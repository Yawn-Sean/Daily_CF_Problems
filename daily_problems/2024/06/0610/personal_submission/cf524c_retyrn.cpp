int n, k, q;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    sort(all(a), greater<int>());
    map<int, int> mp;
    mp[0] = 0;
    for (auto x : a) {
        for (int j = 1; j <= k; j ++) {
            int t = x * j;
            if (!mp.count(t)) mp[t] = j;
        }
    }
    
    cin >> q;
    while (q --) {
        int val;
        cin >> val;
        int res = inf;
        for (auto x : a) {
            for (int j = 1; j * x <= val and j <= k; j ++) {
                if (mp.count(val - j * x)) {
                    res = min(res, j + mp[val - j * x]);
                }
            }
        }
        if (res > k) res = -1;
        cout << res << endl;
    }
}