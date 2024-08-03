int n, m;
map<int, LL> cnt;

void solve() {
    cin >> n >> m;
    map<int, LL> f;
    for (int i = 0; i <= m - 1; i ++) {
        f[i] += n / m;
    }
    for (int i = 1; i <= n % m; i ++) {
        f[i] += 1;
    }
    for (auto [x, y]: f) {
        int now = x * x % m;
        cnt[now] += y;
    }
    LL ans = 0;
    for (auto [x, y]: cnt) {
        int need = (m - x) % m;
        ans += y * cnt[need];
    }
    cout << ans << endl;
}
