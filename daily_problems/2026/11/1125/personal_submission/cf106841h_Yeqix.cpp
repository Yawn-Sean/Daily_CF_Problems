#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<i64, 2>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0] >> f[i][1];
    }
    f.push_back({f[n][0] + 1, 0});

    vector<i64> dp(n + 2), dp0(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        i64 dis = f[i][0] - f[i - 1][0];
        if (f[i][1]) {
            dp[i] = (dp[i - 1] + dp0[i - 1] + dis * 2) % md;
        } else {
            dp[i] = (dp[i - 1] + dis) % md;
        }
        dp0[i] = (dp0[i - 1] + dis) * 2 % md;
    }

    cout << dp[n + 1];
    return 0;
}