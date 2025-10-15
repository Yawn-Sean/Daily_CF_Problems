/*
每天第一步是从船舱走到中心，只能走这个船舱相连的道路
第二步是从中心走到船舱，可以走所有的道路，从而走到某个船舱
每天初始在 i，最后在 j 的方案数，设为 cnt[i][j]
cnt[i][j] 怎么求？
先走短路，则就是 cnt[i][j] += s[i] * (s[j] + l[j])
先走长路，则就是 cnt[i][j] += l[i] * s[j]
dp[i][j][k]: 走 i 天，第 i 天是从 j 走到 k，方案数是多少
dp[1][1][k] 可求
dp[i][j][k] += dp[i - 1][l][j] * cnt[j][k]
O(n * m^3)，考虑使用快速幂优化
需要优化一下状态，只要考虑 dp[i][j]: 走 i 天，最后留在 j
dp[i][j] += dp[i - 1][k] * cnt[k][j]
*/

LL m, n, s[M], l[M];

vector<vector<LL>> transfer;

void meibao() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }

    int mod = 1e9 + 7;
    for (int i = 0; i < m; i++) {
        vector<LL> row;
        for (int j = 0; j < m; j++) {
            row.push_back(s[i] * (s[j] + l[j]) + l[i] * s[j]);
        }
        transfer.push_back(row);
    }

    vector<vector<LL>> res = matrix_qpow(transfer, n, mod);
    vector<vector<LL>> f0;
    vector<LL> row;
    row.push_back(1);
    f0.push_back(row);
    for (int i = 1; i < m; i++) {
        row.push_back(0);
    }
    vector<vector<LL>> final_matrix = matrix_mul(f0, res, mod);
    LL ans = 0;
    for (int i = 0; i < m; i++) {
        ans += final_matrix[0][i];
        ans %= mod;
    }
    cout << ans << "\n";
}   
