#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1e9+7;

int main() {
    int n, r, g, b;
    scanf("%d %d %d %d", &n, &r, &g, &b);
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 1; i < n; i++) {
        int tot = ((dp[i][0] + dp[i][1]) % MOD + dp[i][2]) % MOD;
        dp[i + 1][0] = tot;
        if (i > r) {
            dp[i + 1][0] = (dp[i + 1][0] + (MOD - (dp[i - r][1] + dp[i - r][2]) % MOD)) % MOD;
        } else if (i == r) {
            dp[i + 1][0] = (dp[i + 1][0] + MOD - 1) % MOD;
        }
        dp[i + 1][1] = tot;
        if (i > g) {
            dp[i + 1][1] = (dp[i + 1][1] + (MOD - (dp[i - g][0] + dp[i - g][2]) % MOD)) % MOD;
        } else if (i == g) {
            dp[i + 1][1] = (dp[i + 1][1] + MOD - 1) % MOD;
        }
        dp[i + 1][2] = tot;
        if (i > b) {
            dp[i + 1][2] = (dp[i + 1][2] + (MOD - (dp[i - b][0] + dp[i - b][1]) % MOD)) % MOD;
        } else if (i == b) {
            dp[i + 1][2] = (dp[i + 1][2] + MOD - 1) % MOD;
        }
    }
    printf("%d\n", ((dp[n][0] + dp[n][1]) % MOD + dp[n][2]) % MOD);
    return 0;
}

