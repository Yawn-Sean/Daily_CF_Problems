ll n;

ll cal(ll mx) {
    // 1 t t*t t*t*t
    ll cnt = 0;
    for (int i = 2; (ll)i * i * i <= mx; i ++) {
        cnt += mx / ((ll)i * i * i);
    }
    return cnt;
}
void solve() {
    cin >> n;
    ll l = 1, r = (ll)1e16;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (cal(mid) < n) l = mid + 1;
        else r = mid;
    }
    cout << (cal(l) == n ? l : -1) << endl;
}