int n, m, sum;

void solve() {
    cin >> n >> m >> sum;
    vector<int> a(n), b(m);
    cin >> a >> b;
    
    sort(all(a));
    sort(all(b));
    
    auto cal = [&](int l) -> ll {
        ll res = 0;
        for (int i = n - 1, j = l - 1; j >= 0; j --, i --) {
            auto need = max(0, b[j] - a[i]);
            res += need;
        }
        return res;
    };
    
    int l = 0, r = min(n, m);
    
    while (l < r) {
        auto mid = (l + r + 1) >> 1;
        if (cal(mid) <= sum) l = mid;
        else r = mid - 1;
    }
    cout << l << ' ';
    
    ll res = -sum;
    for (int i = 0; i < l; i ++) {
        res += b[i];
    }
    cout << max(0LL, res) << endl;
}