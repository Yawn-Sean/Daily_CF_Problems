#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr i64 inf = 1e17;

void solve() {
    i64 n, h, k;
    cin >> n >> h >> k;
    vector<array<i64, 2>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0] >> f[i][1];
    }

    sort(f.begin() + 1, f.end(), [&](auto x, auto y) {
        i64 v1 = x[1] - x[0], v2 = y[1] - y[0];
        if (v1 >= 0 && v2 >= 0) {
            return x[0] < y[0];
        }
        if (v1 <= 0 && v2 <= 0) {
            return x[1] > y[1];
        }
        return v1 > v2;
    });

    vector<vector<i64>> dp(n + 1, vector<i64>(k + 1, -inf));
    dp[0][k] = h;
    for (int i = 1; i <= n; i++) {
        auto [x, y] = f[i];
        for (int j = 0; j <= k; j++) {
            if (dp[i - 1][j] > x) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] - x + y);
            }
            if (j < k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
            }
        }
    }

    if (*rgs::max_element(dp[n]) >= 0) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}