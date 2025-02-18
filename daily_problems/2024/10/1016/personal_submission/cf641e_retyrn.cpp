int n;
using ai3 = array<int, 3>;

void solve() {
    cin >> n;
    map<int, vector<ai3>> mp;
    
    for (int i = 0; i < n; i ++) {
        int op, t, x;
        cin >> op >> t >> x;
        mp[x].push_back({op, t, i});
    }
    vector<int> res(n, -1);
    
    for (auto& [_, v] : mp) {
        // 时间离散化
        vector<int> time;
        for (auto& x : v) {
            time.push_back(x[1]);
        }
        sort(all(time));
        
        int len = sz(time);
        Fenwick<int> fen(len);
        
        for (auto& x : v) {
            int op = x[0], t = x[1], id = x[2];
            t = lower_bound(all(time), t) - time.begin();
            if (op == 1) {
                fen.add(t, 1);
            }
            else if (op == 2) {
                fen.add(t, -1);
            }
            else {
                int ans = fen.rangeSum(0, t);
                res[id] = ans;
            }
        }
    }
    
    for (auto x : res) {
        if (x >= 0) cout << x << endl;
    }
}