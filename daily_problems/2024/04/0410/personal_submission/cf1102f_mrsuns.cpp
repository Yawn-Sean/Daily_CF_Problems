void Solve(int TIME) {

    int n, m;cin >> n >> m;
    vvc<int> a(n, vi(m + 1));
    for (int i = 0;i < n;i++) {
        for (int j = 1;j <= m;j++) cin >> a[i][j];
    }
    vvc<int> b(n, vi(n, inf));
    for (int i = 1;i <= m;i++) {
        for (int j = 0;j < n;j++) {
            for (int k = 0;k < n;k++) {
                b[j][k] = min(b[j][k], abs(a[j][i] - a[k][i]));
            }
        }
    }
    vvc<int> c(n, vi(n, inf));
    for (int i = 2;i <= m;i++) {
        for (int j = 0;j < n;j++) {
            for (int k = 0;k < n;k++) {
                c[j][k] = min(c[j][k], abs(a[j][i] - a[k][i - 1]));
            }
        }
    }

    int res = 0;
    int u = (1 << n) - 1;
    for (int i = 0;i < n;i++) {
        vvc<int> f(u + 1, vi(n));f[1 << i][i] = inf;
        for (int mask = 0;mask <= u;mask++) {
            for (int j = 0;j <= n;j++) {
                if (~mask >> j & 1) continue;
                for (int k = 0;k < n;k++) {
                    if (mask >> k & 1) continue;
                    f[mask | (1 << k)][k] = max(f[mask | (1 << k)][k], min(f[mask][j], b[j][k]));
                }
            }
        }

        for (int j = 0;j < n;j++) {
            res = max(res, min(c[i][j], f[u][j]));
        }
    }
    cout << res << endl;


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    PreWork();

    int T = 1;
    //cin >> T;

    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }

    return 0;
}
