#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 100000;
    const int MAXI = 450; 
    const int MOD = 998244353;

    vector<vector<int>> dp(MAXI, vector<int>(M + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i < MAXI; ++i) {
        for (int j = 0; j <= M; ++j) {
            int val = dp[i-1][j];
            if (j >= i) {
                val += dp[i][j - i];
                if (val >= MOD) val -= MOD;
            }
            dp[i][j] = val;
        }
    }

    int t;
    if (!(cin >> t)) return 0;
    vector<int> outs;
    outs.reserve(t);

    while (t--) {
        long long n;
        cin >> n;
        long long ans = 0;
        for (int i = 1; i < MAXI; ++i) {
            long long ii = 1LL * i * i;
            if (ii > n) break;
            if (((n + i) & 1) == 0) {
                long long idx = (n - ii) / 2;
                if (0 <= idx && idx <= M) {
                    ans += dp[i][(int)idx];
                    if (ans >= MOD) ans -= MOD;
                }
            }
        }
        outs.push_back((int)(ans % MOD));
    }

    for (int x : outs) {
        cout << x << '\n';
    }
    return 0;
}
