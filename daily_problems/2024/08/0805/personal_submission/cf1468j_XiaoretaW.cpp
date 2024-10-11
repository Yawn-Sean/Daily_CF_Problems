void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
    }
    sort(all(e));
 
    DSU dsu(n + 1);
    ll ans = 0;
    int big = false;
    for (int i = 0; i < m; i++) {
        if (dsu.merge(e[i][1], e[i][2])) {
            if (e[i][0] >= k) big = true;
            ans += max(0, e[i][0] - k);
        }
    }
 
    if (big) {
        cout << ans << '\n';
        return;
    }
 
    ans = 1e9;
    for (int i = 0; i < m; i++) {
        setmin(ans, 1ll * abs(k - e[i][0]));
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
 
    int tt; cin >> tt;
    while (tt--) solve();
    
    return 0;
}
