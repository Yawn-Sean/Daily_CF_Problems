#define int i64

void solve() {
    int n;
    cin >> n;
    vec<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto p = a;
    vec<int> pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        int cur = max(p[i], p[i - 1] + 1) - p[i];
        pre[i] = pre[i - 1] + cur;
        p[i] = max(p[i], p[i - 1] + 1);
    }
    auto q = a;
    for (int i = n; i >= 1; i--) {
        int cur = max(q[i], q[i + 1] + 1) - q[i];
        suf[i] = suf[i + 1] + cur;
        q[i] = max(q[i], q[i + 1] + 1);
    }

    int ans = 1e18;
    for (int i = 0; i < n; i++) {
        chmin(ans, pre[i] + suf[i + 1] + (p[i] == q[i + 1]));
    }

    cout << ans << '\n';
}
