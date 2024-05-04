// https://codeforces.com/contest/1146/submission/259381250

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n, a, b;
    cin >> n >> a >> b;
    int m = min(a + b, n + 1);
    vector<int> vis(m);
    i64 ans = 0, cur = 1;
    queue<int> Q;
    vis[0] = 1;
    auto visit = [&](int i) {
        Q.emplace(i), vis[i] = 1, cur++;
    };
    for (int i = 0; i < m; ++i) {
        if (i >= a && vis[i - a]) {
            visit(i);
            while (!Q.empty()) {
                int j = Q.front();
                Q.pop();
                if (j >= b && !vis[j - b]) visit(j - b);
                if (j + a <= i && !vis[j + a]) visit(j + a);
            }
        }
        ans += cur;
    }
    if (m <= n + 1) {
        int k = gcd(a, b);
        auto f = [&](int x) {
            i64 t = x / k;
            return (t * k + k) * t / 2 + (x % k + 1) * (t + 1);
        };
        ans += f(n) - f(m - 1);
    }
    cout << ans << endl;
}
