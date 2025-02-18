ll n;

void solve() {
    // 淘汰了x轮 最后的奇数为y
    // y ^ 2 + (1 << (x + 1) - 3) y - n * 2 = 0
    cin >> n;
    vector<ll> res;
    
    for (int x = 0; (1LL << x) - 1 <= n; x ++) {
        ll b = (1LL << (x + 1)) - 3, c = n * 2;
        // 二分出y的值
        ll l = 0, r = (x ? c / b : (ll)sqrtl(c) + 1) + 1;
        chmin(r, (ll)2e9);
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            if (mid * mid + mid * b > c) r = mid - 1;
            else l = mid;
        }
        if ((l & 1) and l * l + l * b == c) {
            ll ans = l << x;
            res.push_back(ans);
        }
    }
    
    sort(all(res));
    for (auto x : res) {
        cout << x << endl;
    }
    
    if (em(res)) {
        cout << -1 << endl;
    }
}