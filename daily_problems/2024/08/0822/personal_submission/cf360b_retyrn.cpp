int n, k;

bool check(const vector<int>& a, ll val) {
    vector<ll> f(n);
    iota(all(f), 0LL);
    for (int i = 0; i < n; i ++) {
        // 枚举上一个不改的位置
        for (int j = 0; j < i; j ++) {
            if (abs(a[i] - a[j]) <= val * (i - j)) {
                chmin(f[i], f[j] + (i - j - 1));
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        if (f[i] + (n - i - 1) <= k) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    if (n < 2) {
        cout << 0 << endl;
        return;
    }
    
    ll mx = 0;
    for (int i = 1; i < n; i ++) {
        chmax(mx, (ll)abs(a[i] - a[i - 1]));
    }
    ll l = 0, r = mx;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (check(a, mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}