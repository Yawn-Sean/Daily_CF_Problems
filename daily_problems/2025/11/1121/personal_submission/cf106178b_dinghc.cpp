#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 998'244'353;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    n = min(n, k);
    vector<int> dp(k + 1, 1);
    for (int i = 1; i < n; i++) {
        vector<int> ndp(k + 1, 0);
        for (int j = 1; j <= k; j++) {
            int l = (i * j + i + 1) / (i + 1);
            int r = (i * j + k) / (i + 1);
            ndp[l] = (ndp[l] + dp[j]) % MOD;
            if (r < k) ndp[r + 1] = (ndp[r + 1] + MOD - dp[j]) % MOD;
        }
        for (int j = 1, cur = ndp[0]; j <= k; j++) {
            cur = (cur + ndp[j]) % MOD;
            dp[j] = cur;
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans = (ans + dp[i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}

