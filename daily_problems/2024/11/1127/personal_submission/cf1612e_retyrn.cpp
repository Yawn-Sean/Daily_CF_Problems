int n;

void solve() {
    cin >> n;
    map<int, vector<int>> mp;
    
    for (int i = 0; i < n; i ++) {
        int m, k;
        cin >> m >> k;
        mp[m].push_back(k);
    }
    
    pii mx = mpr(0, 1);
    vector<int> ans;
    
    // 枚举选择t个通知
    for (int t = 1; t <= 20 and t <= sz(mp); t ++) {
        vector<pii> v;
        for (auto& [m, vec] : mp) {
            int cur = 0;
            for (auto& k : vec) {
                if (t <= k) cur += t;
                else cur += k;
            }
            v.push_back({cur, m});
        }
        sort(all(v), greater<pii>());
        ll sum = 0;
        
        for (int i = 0; i < t; i ++) {
            sum += v[i].fi;
        }
        
        if (sum * mx.se > (ll)mx.fi * t) {
            mx.fi = sum, mx.se = t;
            ans.clear();
            for (int i = 0; i < t; i ++) {
                ans.push_back(v[i].se);
            }
        }
    }
    
    cout << mx.se << endl;
    cout << ans << endl;
}