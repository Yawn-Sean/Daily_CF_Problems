int n, k;

int cal_max(const vector<int>& a, const vector<ll>& s) {
    // 二分找最大值
    int l = a.front(), r = a.back();
    while (l < r) {
        auto mid = (l + r) >> 1;
        int idx = upper_bound(all(a), mid) - a.begin();
        // [idx, n) 全部削减
        ll need = (s[n] - s[idx]) - (ll)(n - idx) * mid;
        if (need > k) l = mid + 1;
        else r = mid;
    }
    return l;
}

int cal_min(const vector<int>& a, const vector<ll>& s) {
    // 二分找最小值
    int l = a.front(), r = a.back();
    while (l < r) {
        auto mid = (l + r + 1) >> 1;
        int idx = lower_bound(all(a), mid) - a.begin() - 1;
        // [0, idx] 全部加
        ll need = (ll)(idx + 1) * mid - s[idx + 1];
        if (need > k) r = mid - 1;
        else l = mid;
    }
    return l;
}

void solve() {
    // 每天最大值-1 最小值+1
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    vector<ll> s(n + 1);
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i - 1];
    }
    
    int mx = cal_max(a, s);
    int mn = cal_min(a, s);
    
    if (mx > mn) {
        cout << mx - mn << endl;
        return;
    }
    // 说明可以完全一样多
    cout << (int)(s.back() % n > 0) << endl;
}