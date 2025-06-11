int n, m;

void solve() {
    cin >> n;
    vector<pii> a(n);
    cin >> a;
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return a[x].se > a[y].se;
    });
    
    cin >> m;
    map<int, vector<int>> mp;
    
    for (int i = 0; i < m; i ++) {
        int x;
        cin >> x;
        mp[x].push_back(i + 1);
    }
    
    int sum = 0;
    vector<pii> res;
    for (auto idx: id) {
        int man = a[idx].fi, pay = a[idx].se;
        auto it = mp.lower_bound(man);
        if (it != mp.end()) {
            auto table = (it->se).back();
            (it->se).pop_back();
            if (em(it->se)) mp.erase(it);
            sum += pay;
            res.emplace_back(idx + 1, table);
        }
    }
    
    sort(all(res));
    cout << sz(res) << ' ' << sum << endl;
    for (auto p : res) {
        cout << p << endl;
    }
}