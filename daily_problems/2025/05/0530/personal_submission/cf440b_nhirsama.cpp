//  B. Balancer
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    i32 n;
    std::cin >> n;
    i32 k = 0;
    std::vector<i32> v(n);
    for (auto &i: v)std::cin >> i, k += i;
    std::vector<i32> dp(n);
    k /= n;
    for (i32 i = 0; i < n - 1; i++) {
        i32 tot = v[i] - k;
        dp[i + 1] = dp[i] + std::abs(tot);
        v[i + 1] += tot;
    }
    std::cout << dp[n - 1] << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}
