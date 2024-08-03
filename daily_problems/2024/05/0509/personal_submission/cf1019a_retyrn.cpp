int n, m;

void solve() {
    cin >> n >> m;
    map<int, vector<int>> mp;
    ll res = 0;
    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        mp[x].pbk(y);
        if (x != 1) res += y;
    }
    for (auto& [k, vec] : mp) {
        sort(all(vec));
    }
    
    // 枚举最终选票
    for (int i = sz(mp[1]); i <= n / 2 + 1; i ++) {
        int have = sz(mp[1]);
        ll cur = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& [k, vec] : mp) {
            if (k == 1) continue;
            for (int j = 0; j < sz(vec); j ++) {
                if (j <= sz(vec) - i) {
                    have ++;
                    cur += vec[j];
                }
                else {
                    q.push(vec[j]);
                }
            }
        }
        // 如果达不到要求
        while (sz(q) and have < i) {
            cur += q.top();
            q.pop();
            have ++;
        }
        if (have >= i) {
            res = min(res, cur);
        }
    }
    cout << res << endl;
}