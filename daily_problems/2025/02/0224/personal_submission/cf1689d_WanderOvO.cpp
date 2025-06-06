/*
一个点为 (x0, y0)，到所有的 (x[i], y[i]) 的最大距离的最小值
最大距离怎么求？
max({
    x0 - x[i] + y0 - y[i],
    x0 - x[i] + y[i] - y0,
    x[i] - x0 + y0 - y[i],
    x[i] - x0 + y[i] - y0
});
= max({
    max(-x[i] - y[i]) + x0 + y0,
    max(-x[i] + y[i]) + x0 - y0,
    max(x[i] - y[i]) - x0 + y0,
    max(x[i] + y[i]) - x0 - y0
});

*/

void meibao() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int mx1 = -INF, mx2 = -INF, mx3 = -INF, mx4 = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                mx1 = max(mx1, -i - j);
                mx2 = max(mx2, -i + j);
                mx3 = max(mx3, i - j);
                mx4 = max(mx4, i + j);
            }
        }
    }
    int res = INF, resx = -1, resy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c = max({
                mx1 + i + j,
                mx2 + i - j,
                mx3 - i + j,
                mx4 - i - j
            });
            if (res > c) {
                res = c;
                resx = i + 1;
                resy = j + 1;
            }
        }
    }
    cout << resx << " " << resy << "\n";
}   
