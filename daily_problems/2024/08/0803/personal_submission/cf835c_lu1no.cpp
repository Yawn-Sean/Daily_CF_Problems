int n, q, c;
int f[15][N][N];

int ask(int t, int x0, int y0, int x, int y) {
    int ans = f[t][x][y] - f[t][x][y0 - 1] - f[t][x0 - 1][y] + f[t][x0 - 1][y0 - 1];
    return ans;
}

void solve() {
    // 最大亮度10 非常关键
    cin >> n >> q >> c;
    vector<node> star(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> star[i][0] >> star[i][1] >> star[i][2];
    }
    for (int t = 0; t <= c; t ++) {
        for (int i = 1; i <= n; i ++) {
            auto [x, y, s] = star[i];
            int now = (s + t) % (c + 1);
            f[t][x][y] += now;
        }
    }
    for (int t = 0; t <= c; t ++) {
        for (int i = 1; i < N; i ++) {
            for (int j = 1; j < N; j ++) {
                f[t][i][j] = f[t][i][j] + f[t][i - 1][j] + f[t][i][j - 1] - f[t][i - 1][j - 1];
            }
        }
    }
    while (q --) {
        int t, x0, y0, x, y;
        cin >> t >> x0 >> y0 >> x >> y;
        t = t % (c + 1);
        cout << ask(t, x0, y0, x, y) << endl;
    }
}
