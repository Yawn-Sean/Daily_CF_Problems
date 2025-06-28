#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n), v(n, 0), c(n, 0);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    std::vector<i64> dp(n + 1, 0);
    for(int i = 0; i < n; i++) {
        i64 x = a[i];
        while((x & 1) == 0) {
            v[i]++;
            x >>= 1;
        }
        c[i] = x;
    }
    
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(c[j] % c[i] == 0 && (v[i] - v[j] == i - j || v[i] <= i - j - 1)) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int q = *max_element(dp.begin(), dp.begin() + n);
    std::cout << n - q << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
