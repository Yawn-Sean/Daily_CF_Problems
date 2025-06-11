void solve() {
    LL d, m;
    cin >> d >> m;
    if (d == 1) {
        cout << 1 % m << endl;
        return;
    }
    int mx = 0;
    for (int i = 31; i >= 0; i --) {
        if (d >> i & 1) {
            mx = i;
            break;
        }
    }
    LL ans = 1;
    for (int i = 0; i <= mx; i ++) {
        if (i != mx)
            ans = ans * ((1LL << i) + 1) % m;
        else 
            ans = ans * (d - (1LL << i) + 1 + 1) % m;
    }
    ans = ((ans - 1) % m + m) % m;
    cout << ans << endl;
}
