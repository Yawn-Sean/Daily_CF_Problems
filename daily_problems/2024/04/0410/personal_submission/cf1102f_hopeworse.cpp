// link https://codeforces.com/contest/1102/submission/255948091



void solve() {
    int n, m;
    cin >> n >> m;
    VII arr(n + 1, VI(m + 1));
    VII dis1(n + 1, VI(n + 1));
    VII dis2(n + 1, VI(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis1[i][j] = inf;
            dis2[i][j] = inf;
            for (int k = 1; k <= m; k++) {
                dis1[i][j] = min(dis1[i][j], abs(arr[i][k] - arr[j][k]));
            }
            // 头是i尾是j
            for (int k = 2; k <= m; k++) {
                dis2[i][j] = min(dis2[i][j], abs(arr[i][k - 1] - arr[j][k]));
            }

        }
    }
    // f[s][i][j] 表示走过s的点，第一个点是i，最后一个点是j的最小代价
    vector<vector<vector<int>>> f(1 << (n), vector<vector<int>>(n + 2, vector<int>(n + 2, -1)));

    f[0][0][0] = inf;
    for (int i = 1; i <= n; i++) {
        f[1 << (i - 1)][i][i] = inf;
    }
//    debug(dis1, dis2);
    for (int s = 0; s < (1 << n); s++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (f[s][i][j] == -1)continue;
                for (int k = 1; k <= n; k++) {
                    if (s & (1 << (k - 1)))continue;
                    f[s | (1 << (k - 1))][i][k] = max(f[s | (1 << (k - 1))][i][k], min(f[s][i][j], dis1[j][k]));
                }
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[(1 << n) - 1][i][j] != -1) {
                f[(1 << n) - 1][i][j] = min(f[(1 << n) - 1][i][j], dis2[i][j]);
            }
//            cout << f[(1 << n) - 1][i][j] << " ";
            ans = max(ans, f[(1 << n) - 1][i][j]);

        }
//        cout << endl;
    }
    cout << ans << endl;
}
