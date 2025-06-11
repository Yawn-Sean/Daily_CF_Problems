/*
有哪些行和列还没有被覆盖，列举一下
随机选的点，行和列有一个没覆盖，就可以覆盖一个新的
dp[i][j]: 已经覆盖了初始时没能覆盖的 i 行 j 列，到覆盖初始时未能覆盖的 n1 行 n2 列还需要多少下
dp[n1][n2] = 0;
dp[i + 1][j + 1]，(n1 - i) * (n2 - j) 种方案
dp[i + 1][j]，(n1 - i) * (j + n - n2) 种方案
dp[i][j + 1]，(i + n - n1) * (n2 - j) 种方案
dp[i][j]，(i + n - n1) * (j + n - n2) 种方案
dp[i][j] = dp[i + 1][j + 1] * p1 + dp[i + 1][j] * p2 + dp[i][j + 1] * p3 + dp[i][j] * p4 + 1
(1 - p4) * dp[i][j] = dp[i + 1][j + 1] * p1 + dp[i + 1][j] * p2 + dp[i][j + 1] * p3 + 1

*/

double dp[N][N];
int n, m;

void meibao() {
    set<int> r, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        r.insert(x);
        c.insert(y);
    }
    int n1 = n - (int)r.size(), n2 = n - (int)c.size();
    dp[n1][n2] = 0;
    for (int i = n1; i >= 0; i--) {
        for (int j = n2; j >= 0; j--) {
            if (i == n1 && j == n2) continue;
            double p1 = 0, p2 = 0, p3 = 0, p4 = 0;
            if (i + 1 <= n1 && j + 1 <= n2) {
                p1 = ((n1 - i) * (n2 - j) * 1.0) / (n * n);
            }
            if (i + 1 <= n1) {
                p2 = ((n1 - i) * (j + n - n2) * 1.0) / (n * n);
            }
            if (j + 1 <= n2) {
                p3 = ((i + n - n1) * (n2 - j) * 1.0) / (n * n);
            }
            p4 = ((i + n - n1) * (j + n - n2) * 1.0) / (n * n);
            dp[i][j] = (dp[i + 1][j + 1] * p1 + dp[i + 1][j] * p2 + dp[i][j + 1] * p3 + 1) / (1 - p4);
        }
    }
    cout << setprecision(15) << dp[0][0] << "\n";
}
