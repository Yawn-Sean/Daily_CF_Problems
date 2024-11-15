/*
给的图没有自环
显然 p 中第一个点和最后一个点必须出现在所选的子序列中，不然可以走到中间就不走了，或者不从起点开始走
考虑以 u 点结尾的满足条件的最短子序列的长度
考虑从哪个前驱 v 转移过来，可以枚举 u 前面的 n - 1 个点
因为假如枚举了 n 个点，那么就一定会绕路，不是最短路了
预处理两两之间的最短路长度，然后枚举 v 时就可以计算 v 到 u 最短路是否长度和序列中长度一样
*/

int d[M][M];
string s[M];
int dp[N], n, m, p[N], pre[N];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void meibao() {
    cin >> n;
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '1') {
                d[i][j] = 1;
            }
        }
    }
    floyd();
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    dp[1] = 1;
    for (int i = 2; i <= m; i++) {
        for (int j = i - 1; j > 0 && i - j <= n; j--) {
            int u = p[i], v = p[j];
            if (d[v][u] == i - j) {
                if (dp[i] > dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }
    cout << dp[m] << "\n";
    vector<int> path;
    int cur = m;
    while (cur > 0) {
        path.push_back(p[cur]);
        cur = pre[cur];
    }
    reverse(path.begin(), path.end());
    for (auto v : path) {
        cout << v << " ";
    }
    cout << "\n";
}
