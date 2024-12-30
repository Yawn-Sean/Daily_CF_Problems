/*
给一个单调不降子序列，如何求不超过它的子序列个数（不一定单调不减）?
其实就是这些数乘起来

dp[i][j]: 考虑前 i 个数，以数字 j 结尾的所有本质不同且单调不减的子序列，不超过自己的有多少个
dp[i][j] = dp[i - 1][j], j != a[i], 直接继承之前的结果
dp[i][a[i]] = a[i] * (sum(dp[i - 1][j]) + 1), j <= a[i]
*/

int T;
LL dp[M], a[N], n;
BIT bit;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[a[1]] = a[1];
    bit.init(M - 1);
    bit.add(a[1], dp[a[1]]);
    for (int i = 2; i <= n; i++) {
        LL old_cnt = bit.query(a[i]) - bit.query(a[i] - 1);
        LL new_cnt = (bit.query(a[i]) + 1) * a[i] % MOD1;
        bit.add(a[i], -old_cnt);
        bit.add(a[i], new_cnt);
    }
    cout << bit.query(M - 1) << "\n";
}      