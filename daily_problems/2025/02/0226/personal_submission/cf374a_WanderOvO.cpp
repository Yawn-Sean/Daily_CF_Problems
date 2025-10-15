void meibao() {
    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;
    int res = INF;
    int tx[4] = {1, 1, n, n}, ty[4] = {1, m, 1, m};
    for (int k = 0; k < 4; k++) {
        int dx = abs(i - tx[k]), dy = abs(j - ty[k]);
        if (dx % a == 0 && dy % b == 0) {
            int cnt1 = dx / a, cnt2 = dy / b;
            if (cnt1 % 2 == cnt2 % 2) {
                if (cnt1 > cnt2) {
                    if (ty[k] + b <= m || ty[k] - b > 0) {
                        res = min(res, max(cnt1, cnt2));
                    }
                } else if (cnt1 < cnt2) {
                    if (tx[k] + a <= n || tx[k] - a > 0) {
                        res = min(res, max(cnt1, cnt2));
                    }
                } else {
                    res = min(res, max(cnt1, cnt2));
                }
            }
        }
    }
    if (res == INF) {
        cout << "Poor Inna and pony!\n";
    } else {
        cout << res << "\n";
    }
}   
