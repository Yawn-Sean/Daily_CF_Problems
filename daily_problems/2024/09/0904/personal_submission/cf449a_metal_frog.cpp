int n, m, k;
 
ll calc(int x) {
    return 1ll * x * (m / max(1, k - n / x + 2));
}
 
void solve() {
    cin >> n >> m >> k;
    ll ans = 0;
    int lim = sqrt(1e9);
    for (int i = 1; i <= min(n, lim); i ++) {
        ans = max(ans, calc(i));
        ans = max(ans, calc(n / i));
    }
    if (ans == 0) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}
