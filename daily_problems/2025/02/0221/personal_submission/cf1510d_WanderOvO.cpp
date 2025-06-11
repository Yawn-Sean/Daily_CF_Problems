/*
考虑个位数，则只需要考虑每个数的个位数，使用一个 DP 很容易判断是否有凑出来成绩为这个个位数的方案
乘积是非常大的数，甚至表示长度可达到 1e8，大概率是通过间接的方式来比大小的
取对数，把乘积转化为加法，就好做了，DP 时直接可以设 dp[i][j] 为前 i 个数最后结尾为 j 的乘积的对数最大值
*/

LL n, d, a[N];
double dp[N][M];
int from[N][M];

void meibao() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][1] = 0;
    dp[1][a[1] % 10] = log2(a[1]);
    from[1][a[1] % 10] = 1;
    if (a[1] % 10 != 1) {
        dp[1][1] = 0;
        from[1][1] = 1;
    }
    // cout << dp[1][a[1] % 10] << "\n";
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i + 1][j] = dp[i][j];
            from[i + 1][j] = j;
        }
        for (int j = 0; j < 10; j++) {
            int b = j * a[i + 1] % 10;
            double c = dp[i][j] + log2(a[i + 1]);
            if (c > dp[i + 1][b]) {
                dp[i + 1][b] = c;
                from[i + 1][b] = j;
            }
        }
    }

    if (dp[n][d] < 0) {
        cout << "-1\n";
        return;
    }

    vector<int> chosen;
    int cur = d;
    for (int i = n; i > 0; i--) {
        int last = from[i][cur];
        if (fabs(dp[i - 1][last] - dp[i][cur]) > eps || (a[i] % 10 == 1)) {
            chosen.push_back(a[i]);
        }
        cur = last;
    }
    if (chosen.size() == 0) {
        cout << "-1\n";
        return;
    }
    cout << chosen.size() << "\n";
    for (auto val : chosen) {
        cout << val << " ";
    }
}
