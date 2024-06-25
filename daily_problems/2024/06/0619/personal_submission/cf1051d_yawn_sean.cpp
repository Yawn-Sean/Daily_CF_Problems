#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(4, vector<int>(2 * n + 1)), ndp(4, vector<int>(2 * n + 1));
    int mod = 998244353;

    dp[0][1] = 1;
    dp[1][2] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;

    vector<vector<int>> grid = {
        {0, 1, 1, 1},
        {0, 0, 2, 0},
        {0, 2, 0, 0},
        {1, 1, 1, 0}
    };

    for (int _ = 1; _ < n; _ ++) {
        for (int msk = 0; msk < 4; msk ++)
            for (int j = 0; j <= k; j ++)
                if (dp[msk][j] > 0)
                    for (int nmsk = 0; nmsk < 4; nmsk ++) {
                        int nj = j + grid[msk][nmsk];
                        ndp[nmsk][nj] += dp[msk][j];
                        if (ndp[nmsk][nj] >= mod) ndp[nmsk][nj] -= mod;
                    }
        for (int msk = 0; msk < 4; msk ++)
            for (int j = 0; j <= k; j ++)
                dp[msk][j] = ndp[msk][j], ndp[msk][j] = 0;
    }

    int ans = 0;
    for (int msk = 0; msk < 4; msk ++) {
        ans += dp[msk][k];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << '\n';

    return 0;
}