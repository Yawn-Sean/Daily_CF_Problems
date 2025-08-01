#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1e9+7;
constexpr int N = 5000;
char s[N + 1], t[N + 1];

int main() {
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            dp[i][j] = dp[i][j + 1];
            if (s[i] == t[j]) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j + 1] + 1) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + dp[i][0]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}

