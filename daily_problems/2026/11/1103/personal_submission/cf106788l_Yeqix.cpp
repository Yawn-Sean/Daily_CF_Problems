#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto& x : w) {
        cin >> x;
    }

    vector dp(2001, vector<int>(1 << n, -1));
    dp[0][0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i <= 1000; i++) {
            if (dp[i][mask] == -1) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) {
                    continue;
                }
                int nxt = mask | (1 << j), w0 = dp[i][mask] + w[j], w1 = abs(dp[i][mask] - w[j]);
                dp[max(w0, i)][nxt] = max(dp[max(w0, i)][nxt], w0);
                dp[max(w1, i)][nxt] = max(dp[max(w1, i)][nxt], w1);
            }
        }
    }

    for (int i = 0; i <= 1000; i++) {
        if (dp[i].back() != -1) {
            cout << i;
            return 0;
        }
    }
    return 0;
}