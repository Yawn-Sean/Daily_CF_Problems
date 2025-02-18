const int N = 203;
double f[N][N][N];


void solve() {
    int n, k, l;
    cin >> n >> l >> k;
    vector<int> a(n);
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        p[i] = (double)t / 100; 
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int x, int y) -> bool {
        return a[x] > a[y];
    });
    f[0][0][k] = 1.0;
    for (int i = 1; i <= n; i++) {
        int id = ids[i - 1];
        if (a[id] < 0) {
            for (int j = 0; j <= n; j++) {
                for (int u = 0; u <= 200; u++) {
                    if (f[i - 1][j][u]) {
                        f[i][j][u] += (1.0 - p[id]) * f[i - 1][j][u];
                        if (u) {
                            f[i][j + 1][u - 1] += p[id] * f[i - 1][j][u];
                        }
                        
                    }
                }
            }
            continue;
        }
        for (int j = 0; j <= n; j++) {
            for (int u = 0; u <= 200; u++) {
                if (f[i - 1][j][u]) {
                    f[i][j][u] += (1.0 - p[id]) * f[i - 1][j][u];
                    f[i][j + 1][min(200, u + a[id])] += p[id] * f[i - 1][j][u];
                }
            }
        }
    }
    double ans = 0;
    for (int i = l; i <= n; i++) {
        for (int j = 0; j <= 200; j++) {
            ans += f[n][i][j];
        }
    }
    cout << fixed << setprecision(15) << ans;
    return;
}