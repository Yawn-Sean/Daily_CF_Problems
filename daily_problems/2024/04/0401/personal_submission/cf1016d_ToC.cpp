// https://codeforces.com/contest/1016/submission/254376989
int n, t, m;
int a[128], b[128];

void sol()
{
    cin >> n >> m;
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }
    int y = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        y ^= b[i];
    }
    if (x != y) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<vector<int>> c(n, vector<int>(m));
        c[0][0] = a[0];
        for (int i = 1; i < m; i++) c[0][0] ^= b[i];
        for (int i = 1; i < m; i++) c[0][i] = b[i];
        for (int i = 1; i < n; i++) c[i][0] = a[i];
        for (auto &row : c) {
            for (auto &e : row)
                cout << e << " ";
            cout << '\n';
        }
    }
}
