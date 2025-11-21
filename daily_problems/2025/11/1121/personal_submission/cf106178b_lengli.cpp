#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n, k;
    if (!(cin >> n >> k)) return 0;

    n = min(n, k);

    vector<int64> dp(k + 1, 0);
    dp[0] = 1;

    for (int64 i = 1; i <= n; ++i) {
        vector<int64> ndp(k + 1, 0);

        for (int64 j = 0; j <= k; ++j) {
            if (dp[j] == 0) continue;
            // start = j * (i - 1) + 1
            // end   = j * (i - 1) + k
            int64 start = j * (i - 1) + 1;
            int64 end   = j * (i - 1) + k;

            // left = ceil(start / i)
            int64 left = (start + i - 1) / i;
            // right = floor(end / i)
            int64 right = end / i;

            if (left > k || left > right) continue; // no valid contribution
            // add dp[j] to ndp[left]
            ndp[left] += dp[j];
            if (ndp[left] >= MOD) ndp[left] -= MOD;

            // subtract dp[j] at ndp[right+1] if in range
            if (right + 1 <= k) {
                ndp[right + 1] -= dp[j];
                if (ndp[right + 1] < 0) ndp[right + 1] += MOD;
            }
        }

        // prefix sum and mod
        for (int idx = 1; idx <= k; ++idx) {
            ndp[idx] += ndp[idx - 1];
            ndp[idx] %= MOD;
            if (ndp[idx] < 0) ndp[idx] += MOD;
        }

        dp.swap(ndp);
    }

    int64 ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += dp[i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << (ans % MOD) << "\n";
    return 0;
}
