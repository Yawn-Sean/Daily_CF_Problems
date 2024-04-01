int n, m, a[N], b[N];
int res[N][N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int x1 = 0, x2 = 0;
    for (int i = 1; i < n; i++) {
        res[i][m] = a[i];
        x1 ^= a[i];
    }
    for (int j = 1; j < m; j++) {
        res[n][j] = b[j];
        x2 ^= b[j];
    }
    if ((x1 ^ b[m]) == (x2 ^ a[n])) {
        cout << "YES\n";
        res[n][m] = (x1 ^ b[m]);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "NO\n";
    }
}             