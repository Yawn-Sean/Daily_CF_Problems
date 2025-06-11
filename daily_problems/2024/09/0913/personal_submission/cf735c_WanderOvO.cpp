/*
假设最多的人现在赢了 cnt 场，则需要至少挑战一个赢了 cnt - 1 场的人
设 dp[cnt] 为产生一个赢了 cnt 场的人需要淘汰多少人
dp[0] = 0, dp[1] = 1
dp[cnt] = dp[cnt - 1] + dp[cnt - 2] + 1
*/

int T;

void solve1() {
    LL n;
    cin >> n;
    vector<LL> dp(100, 0);
    dp[1] = 1;
    for (int i = 2; ; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
        if (dp[i] >= n) {
            break;
        }
    }
    LL res = 0;
    for (int i = 1; i < 100; i++) {
        if (dp[i] != 0 && dp[i] < n) {
            res = i;
        }
    }
    cout << res << "\n";
}                                                                                                                  
