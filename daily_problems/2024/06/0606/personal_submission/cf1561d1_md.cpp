// 0606
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, m;
    std::cin >> n >> m;

    std::vector<i64> dp(n + 1);
    dp[1] = 1;

    i64 prefix = 1;

    for (i64 i = 2; i <= n; ++i) {
        dp[i] = prefix;
        for (i64 l = 2, r = 0; l <= i; l = r + 1) {
            r = i / (i / l);
            dp[i] = (dp[i] + dp[i / l] * (r - (l - 1)) % m) % m;
        }

        prefix = (prefix + dp[i]) % m;
    }

    std::cout << dp[n] << std::endl;

    return 0;
}