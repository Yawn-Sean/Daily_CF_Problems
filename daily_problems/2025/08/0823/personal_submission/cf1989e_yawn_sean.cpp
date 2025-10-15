#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, mod = 998244353;
    cin >> n >> k;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0)), dp_acc(k + 1, vector<int>(n + 1, 0));

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    for (int i = 1; i <= n; i ++) {
        dp[1][i] = 1;
        dp_acc[1][i] = i;

        for (int j = 2; j <= k; j ++) {
            dp[j][i] = dp[j - 1][i - 1];
            if (i >= 3) add(dp[j][i], dp_acc[j - 1][i - 3]);
            dp_acc[j][i] = dp_acc[j][i - 1];
            add(dp_acc[j][i], dp[j][i]);
        }

        add(dp[k][i], dp[k][i - 1]);
        if (i >= 3) add(dp[k][i], dp_acc[k][i - 3]);

        dp_acc[k][i] = dp_acc[k][i - 1];
        add(dp_acc[k][i], dp[k][i]);
    }

    int ans = 0;
    add(ans, dp[k][n]);
    add(ans, dp[k - 1][n - 2]);
    add(ans, dp[k][n - 2]);

    cout << ans;

    return 0;
}