#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<i64, 2>> f(n);
    for (auto& [x, y] : f) {
        cin >> x >> y;
    }

    auto get = [&](i64 x, i64 y) -> ld {
        vector dp(n + 1, vector<ld>(1 << n, 1e18));
        for (int i = 0; i < n; i++) {
            dp[i][1 << i] = 0;
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) {
                    for (int k = 0; k < n; k++) {
                        if (mask >> k & 1) {
                            continue;
                        }
                        auto [a, b] = f[j];
                        auto [c, d] = f[k];
                        array<i64, 2> V = {a - c, b - d};
                        ld g = abs(V[0] * x + V[1] * y), gm = x * x + y * y;
                        ld res = sqrtl(-g * g + (V[0] * V[0] + V[1] * V[1]) * gm) + g;
                        res /= sqrtl(gm);
                        dp[k][mask | (1 << k)] = min(dp[k][mask | (1 << k)], dp[j][mask] + res);
                    }
                }
            }
        }
        ld ans = 9e18;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i].back());
        }
        return ans;
    };

    ld ans = 9e18;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, get(f[i][0] - f[j][0], f[i][1] - f[j][1]));
        }
    }

    cout << fixed << setprecision(12) << ans;
    return 0;
}