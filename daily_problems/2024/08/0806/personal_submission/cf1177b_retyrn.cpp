ll n;

ll count(ll x) {
    ll cnt = 9, mx = 9, len = 1;
    ll res = 0;
    while (mx <= x) {
        res += cnt * len;
        cnt *= 10;
        mx = (mx + 1) * 10 - 1;
        len += 1;
    }
    mx = (mx + 1) / 10 - 1;
    res += (x - mx) * len;
    return res;
}

void solve() {
    cin >> n;
    ll l = 1, r = n;
    while (l < r) {
        auto mid = (l + r + 1) >> 1;
        if (count(mid) > n) r = mid - 1;
        else l = mid;
    }
    n -= count(l);
    if (n == 0) cout << l % 10 << endl;
    else {
        l ++;
        vector<int> p;
        while (l > 0) {
            p.push_back(l % 10);
            l /= 10;
        }
        reverse(all(p));
        cout << p[n - 1] << endl;
    }
}