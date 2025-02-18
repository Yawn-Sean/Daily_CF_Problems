ll n;
int k;

void solve() {
    cin >> n >> k;
    vector<int> v;
    for (int i = 60; i >= 0; i --) {
        if (n >> i & 1) v.push_back(i);
    }
    if (sz(v) > k) {
        cout << "No" << endl;
        return;
    }
    
    for (int t = -60; t <= v[0]; t ++) {
        // 大于等于的都要变
        vector<int> res;
        bool ok = true;
        for (auto x : v) {
            if (x >= t) {
                // 可以变成 2^(x-t)个
                if (x - t >= 20 or sz(res) + (1 << (x - t)) > k) {
                    ok = false;
                    break;
                }
                for (int i = 0; i < (1 << (x - t)); i ++) {
                    res.push_back(t);
                }
            }
            else {
                res.push_back(x);
            }
        }
        
        if (!ok or sz(res) > k) continue;
        
        while (sz(res) < k) {
            auto val = res.back();
            res.pop_back();
            res.push_back(val - 1);
            res.push_back(val - 1);
        }
        cout << "Yes" << endl;
        cout << res << endl;
        return;
    }
    cout << "No" << endl;
}