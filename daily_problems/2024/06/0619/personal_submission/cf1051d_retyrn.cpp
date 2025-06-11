int n, m;
int f[maxn][maxn << 1][4];

int get(int u, int v) {
    if (u == v) return 0;
    if (u == 0) {
        if (v == 3) return 1;
        return 0;
    }
    if (u == 1) {
        if (v == 2) return 2;
        return 1;
    }
    if (u == 2) {
        if (v == 1) return 2;
        return 1;
    }
    if (v == 1 or v == 2) return 0;
    return 1;
}

void solve() {
    cin >> n >> m;
    f[0][1][0] = 1;
    f[0][2][1] = 1;
    f[0][2][2] = 1;
    f[0][1][3] = 1;
    
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int k1 = 0; k1 < 4; k1 ++) {
                for (int k2 = 0; k2 < 4; k2 ++) {
                    int t = j - get(k1, k2);
                    if (t >= 1) {
                        f[i][j][k1] += f[i-1][t][k2];
                        f[i][j][k1] %= mod;
                    }
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 4; i ++) {
        res = (res + f[n-1][m][i]) % mod;
    }
    cout << res << endl;
}