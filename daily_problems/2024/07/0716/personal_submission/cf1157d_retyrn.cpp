int n, k;

ll cal_min(int st, int len) {
    return (ll)(st + st + len - 1) * len / 2;
}

ll cal_max(int st, int len) {
    if (len >= 30) return inf2;
    return ((1ll << len) - 1) * st;
}

void solve() {
    cin >> n >> k;
    vector<int> res;
    
    for (int i = 0; i < k; i ++) {
        int len = k - i;
        int l = (em(res) ? 1 : res.back() + 1), r = min(n / len, (em(res) ? inf : res.back() * 2));
        if (l > r) {
            cout << "NO" << endl;
            return;
        }
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            auto mn = cal_min(mid, len);
            if (mn > n) r = mid - 1;
            else l = mid;
        }
        auto mx = cal_max(l, len);
        if (mx < n) {
            cout << "NO" << endl;
            return;
        }
        res.push_back(l);
        n -= l;
    }
    if (n > 0) res.back() += n;
    cout << "YES" << endl;
    cout << res << endl;
}