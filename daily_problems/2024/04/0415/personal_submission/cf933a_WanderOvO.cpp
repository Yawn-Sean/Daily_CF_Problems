/*
翻转 [l, r]，使得整个序列的最长不下降子序列最长
枚举 [l, r]，翻转，然后直接求最长不降子序列(O(n^3logn))

羊：数组中只有 1 和 2 两种元素！
最长不降子序列要么是 1，要么是 2，要么是 1 2
翻转只会影响 1 2 这种情况的答案
我们分别求前 i 个数里面形如 1，1 2，1 2 1，1 2 1 2 的子序列的最长长度即可
*/

int T;
int n, a[N], dp[N][4];                                                                                                               

void solve2() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
        } else {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]) + 1;
        }
        dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1]);
        dp[i][2] = max(dp[i][2], dp[i - 1][2]);
        dp[i][3] = max(dp[i][3], dp[i - 1][3]);
        dp[i][1] = max(dp[i][1], dp[i][0]);
        dp[i][2] = max(dp[i][2], dp[i][1]);
        dp[i][3] = max(dp[i][3], dp[i][2]);
    }
    cout << dp[n][3];
}