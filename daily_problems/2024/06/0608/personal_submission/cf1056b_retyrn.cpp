int n, m;

void solve() {
    cin >> n >> m;
    vector<ll> cnt(m); // 一个数的平方对m取模
    int t = (n + 1) / m;
    for (int i = 0; i < m; i ++) {
        cnt[(i * i) % m] += t;
    }
    for (int i = t * m; i <= n; i ++) {
        cnt[(i % m) * (i % m) % m] += 1;
    }
    cnt[0] -= 1;
    ll res = 0;
    for (int i = 0; i < m; i ++) {
        int aim = (m - i) % m;
        res += cnt[i] * cnt[aim];
    }
    cout << res << endl;
}