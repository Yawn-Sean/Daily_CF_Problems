int n, x, y;
ll a, b, k;

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void solve() {
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
        p[i] /= 100;
    }
    sort(all(p), greater<int>());
    
    cin >> x >> a;
    cin >> y >> b;
    
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    
    cin >> k;
    ll ab = lcm(a, b);
    vector<int> cnt(3);
    
    auto check = [&](int len) -> bool {
        // 容斥原理
        cnt[0] = len / ab;
        cnt[1] = len / a - cnt[0];
        cnt[2] = len / b - cnt[0];
        ll cur = 0;
        for (int i = 0; i < cnt[0]; i ++) {
            cur += (ll)p[i] * (x + y);
            if (cur >= k) return true;
        }
        for (int i = cnt[0]; i < cnt[0] + cnt[1]; i ++) {
            cur += (ll)p[i] * x;
            if (cur >= k) return true;
        }
        for (int i = cnt[0] + cnt[1]; i < cnt[0] + cnt[1] + cnt[2]; i ++) {
            cur += (ll)p[i] * y;
            if (cur >= k) return true;
        }
        return false;
    };
    
    // 二分答案
    int l = 1, r = n;
    if (!check(n)) {
        cout << -1 << endl;
        return;
    }
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}