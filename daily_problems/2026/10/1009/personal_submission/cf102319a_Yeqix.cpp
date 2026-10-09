#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> c(n);
    for (auto& x : c) {
        cin >> x;
    }

    vector<int> dp(r + 1, inf);
    dp[0] = 0;
    for (int i = 0; i <= r; i++) {
        for (const auto& v : c) {
            if (i + v <= r) {
                dp[i + v] = min(dp[i + v], dp[i] + 1);
            }
        }
    }

    int res = 0;
    for (int i = l; i <= r; i++) {
        res += dp[i];
    }

    int ans = 0;
    for (int i = 2; i <= r; i++) {
        int sum = 0;
        for (int j = l; j <= r; j++) {
            int now = dp[j];
            for (int k = 1; k * i <= j; k++) {
                now = min(now, dp[j - k * i] + k);
            }
            sum += now;
        }

        if (sum < res) {
            ans = i, res = sum;
        }
    }

    cout << ans;
    return 0;
}