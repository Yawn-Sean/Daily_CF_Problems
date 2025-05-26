#include <array>
#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
struct ball {
    int x, c;
};
void solve() {
    int n;
    std::cin >> n;
    std::vector<ball> a(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].c;
    }
    std::sort(a.begin() + 1, a.end(), [](ball x, ball y) {
        return x.x < y.x;
    });

    const i64 inf = 1E16;
    std::array<i64, 3001> dp[2];
    for(int i = 1; i <= n; i++) {
        dp[0][i] = dp[1][i] = inf; 
    }

    dp[1][1] = a[1].c;
    for(int i = 2; i <= n; i++) {
        i64 pre = a[i].x;
        for(int j = i - 1; j > 0; j--) {
            dp[0][i] = std::min(dp[0][i], dp[1][j] + pre - 1LL * (i - j) * a[j].x);
            pre += a[j].x;
        }
        dp[1][i] = std::min(dp[0][i - 1], dp[1][i - 1]) + a[i].c;
    }

    std::cout << std::min(dp[0][n], dp[1][n]) << "\n";
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
