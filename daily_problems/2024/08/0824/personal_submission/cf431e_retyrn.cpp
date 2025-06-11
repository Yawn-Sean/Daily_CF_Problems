int n, q;

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    
    map<int, int> mp;
    for (auto x : a) {
        mp[x] = 0;
    }
    
    vector<vector<ll>> ops(q);
    for (int i = 0; i < q; i ++) {
        int op;
        cin >> op;
        if (op == 1) {
            ops[i].resize(3);
            ops[i][0] = 1;
            cin >> ops[i][1] >> ops[i][2];
            ops[i][1] -= 1;
            mp[ops[i][2]] = 0;
        }
        else {
            ops[i].resize(2);
            ops[i][0] = 2;
            cin >> ops[i][1];
        }
    }
    
    int idx = 1;
    for (auto& [k, v] : mp) {
        v = idx ++;
    }
    int m = idx;
    
    Fenwick<int> fen1(m + 2);
    Fenwick<ll> fen2(m + 2);
    
    
    auto cal = [&](double x) {
        ll val = floor(x);
        if (val + 1 <= mp.begin()->fi) return 0.0;
        if (val >= mp.rbegin()->fi) {
            return x * n - fen2.rangeSum(0, m + 1);
        }
        auto it = mp.upper_bound((int)val);
        it --;
        int p = it->se;
        // dbg(p);
        int cnt = fen1.rangeSum(0, p + 1);
        // dbg(val, cnt);
        return x * cnt - fen2.rangeSum(0, p + 1);
    };
    
    for (auto x : a) {
        fen1.add(mp[x], 1);
        fen2.add(mp[x], x);
    }
    
    for (int i = 0; i < q; i ++) {
        int op = ops[i][0];
        if (op == 1) {
            int id = ops[i][1], val = ops[i][2];
            fen1.add(mp[a[id]], -1);
            fen2.add(mp[a[id]], -a[id]);
            a[id] = val;
            fen1.add(mp[a[id]], 1);
            fen2.add(mp[a[id]], a[id]);
        }
        else {
            // 二分答案
            ll need = ops[i][1];
            double l = 0.0, r = need + 1e9;
            while (r - l > 1e-5) {
                auto mid = (l + r) / 2;
                if (cal(mid) >= need) r = mid;
                else l = mid;
            }
            cout << l << endl;
        }
    }
}