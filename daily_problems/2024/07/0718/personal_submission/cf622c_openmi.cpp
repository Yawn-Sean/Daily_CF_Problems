void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), l(n);
    rep (i, 0, n) {
        cin >> a[i];
    }
    l[0] = -1;
    rep (i, 1, n) {
        if (a[i] != a[i - 1]) l[i] = i - 1;
        else l[i] = l[i-1];
    }
    
    while (m--) {
        int ql, qr, x;
        cin >> ql >> qr >> x;
        ql--, qr--;
        if (a[ql] != x) cout << ql + 1 << nl;
        else if (a[qr] != x) cout << qr + 1 << nl;
        else if (l[qr] > ql) cout << l[qr] + 1 << nl;
        else cout << -1 << nl;
    }
}
