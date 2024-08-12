int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    vector<int> l(n + 1), r(n + 1);
    cin >> a >> b;
    vector<int> need(n + 1, 0);
    for (int i = 0; i < n; i ++) {
        if (i) l[a[i]] = a[i - 1];
        if (i + 1 < n) r[a[i]] = a[i + 1];
    }
    for (auto x : b) {
        need[x] = 1;
    }
    
    auto check = [&](int x) {
        return x > 0 and (!need[x]);
    };
    auto del = [&](int x) {
        if (x <= 0) return;
        if (l[x] > 0) {
            r[l[x]] = r[x];
        }
        if (r[x] > 0) {
            l[r[x]] = l[x];
        }
    };
    
    int res = 1;
    for (auto x : b) {
        auto L = check(l[x]), R = check(r[x]);
        if (L and R) {
            res = (res * 2) % mod;
            del(l[x]);
        }
        else if (L) {
            del(l[x]);
        }
        else if (R) {
            del(r[x]);
        }
        else {
            cout << 0 << endl;
            return;
        }
        need[x] = 0;
    }
    cout << res << endl;
}