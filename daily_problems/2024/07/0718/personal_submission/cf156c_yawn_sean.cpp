#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int mod = 1e9 + 7, n = 100;

    vector<vector<int>> dp(n + 1, vector<int>(25 * n + 1));
    dp[0][0] = 1;

    vector<int> dp_acc(25 * n + 1);

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= 25 * n; j ++) {
            dp_acc[j+1] = dp_acc[j] + dp[i-1][j];
            if (dp_acc[j+1] >= mod) dp_acc[j+1] -= mod;
        }
        for (int j = 0; j <= 25 * i; j ++) {
            dp[i][j] = dp_acc[j+1] - dp_acc[max(j-25, 0)];
            if (dp[i][j] < 0) dp[i][j] += mod;
        }
    }

    int t;
    cin >> t;
    while (t --) {
        string s;
        cin >> s;
        int l = s.size(), x = 0;
        for (auto &c: s) x += c - 'a';
        cout << (dp[l][x] ? dp[l][x] - 1 : mod - 1) << '\n';
    }

    return 0;
}