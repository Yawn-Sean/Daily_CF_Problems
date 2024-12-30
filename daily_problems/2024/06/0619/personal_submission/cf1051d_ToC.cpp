// https://codeforces.com/contest/1051/submission/266636518
int n, m, k;
/*
    0表示白，1表示黑
    f[i][j][0][1]是前i列有j个cc，且第i列的颜色是白黑
*/
LL f[MAXN][MAXN * 2][2][2];
void sol()
{
    cin >> n >> k;
    f[1][1][0][0] = 1, f[1][1][1][1] = 1;
    f[1][2][0][1] = 1, f[1][2][1][0] = 1;
    vector<PII> tail {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 2 * i; j++) {
            for (int k = 0; k < 4; k++) {
                auto [t1, t2] = tail[k];
                if (k == 0)
                    f[i][j][t1][t2] = (f[i - 1][j][0][0] + f[i - 1][j][0][1] + f[i - 1][j][1][0] + f[i - 1][j - 1][1][1]) % mod2;
                else if (k == 1)
                    f[i][j][t1][t2] = (f[i - 1][j - 1][0][0] + f[i - 1][j][0][1] + (j > 2 ? f[i - 1][j - 2][1][0] : 0) + f[i - 1][j - 1][1][1]) % mod2;
                else if (k == 2)
                    f[i][j][t1][t2] = (f[i - 1][j - 1][0][0] + (j > 2 ? f[i - 1][j - 2][0][1] : 0) + f[i - 1][j][1][0] + f[i - 1][j - 1][1][1]) % mod2;
                else 
                    f[i][j][t1][t2] = (f[i - 1][j - 1][0][0] + f[i - 1][j][0][1] + f[i - 1][j][1][0] + f[i - 1][j][1][1]) % mod2;
            }
        }
    }
    LL res = 0;
    for (int i = 0; i < 4; i++) {
        auto [t1, t2] = tail[i];
        (res += f[n][k][t1][t2]) %= mod2;
    }
    cout << res << '\n';
}
