void solve() {
    ll m;
    cin >> m;
    ll lo = 0, hi = 1e16;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        ll cnt = 0;
        for (ll i = 2; i * i * i <= mid; i++) {
            cnt += mid / (i * i * i);
        }
        if (cnt < m) lo = mid + 1;
        else hi = mid;
    }
    ll cnt = 0;
    for (ll i = 2; i * i * i <= lo; i++) {
        cnt += lo / (i * i * i);
    }
    if (cnt != m) cout << "-1\n";
    else cout << lo << "\n";
}
 
