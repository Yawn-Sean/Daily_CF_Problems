int A, B, n;

void solve() {
    cin >> A >> B >> n;
    while (n --) {
        int L, t, m;
        cin >> L >> t >> m;
        if (A + (ll)(L - 1) * B > t) {
            cout << -1 << endl;
            continue;
        }
        ll l = L, r = min((ll)t * m + L + 1, (ll)(t - A) / B + 1);
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            ll need = (A + (ll)(L - 1) * B + A + (ll)(mid - 1) * B) * (mid - L + 1) / 2;
            if (need <= (ll)t * m) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}