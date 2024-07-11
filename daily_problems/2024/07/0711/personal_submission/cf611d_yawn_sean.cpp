#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mod = 1e9 + 7;
    string s;
    cin >> n >> s;

    vector<int> lcp(n * (n + 1) / 2), dp(n * (n + 1) / 2);

    function<int(int, int)> f = [&] (int x, int y) {
        return x * (x + 1) / 2 + y;
    };

    for (int i = n - 1; i >= 0; i --)
        for (int j = 0; j < i; j ++)
            if (s[j] == s[i]) {
                lcp[f(i, i - j)] = 1;
                if (i + 1 < n) lcp[f(i, i - j)] += lcp[f(i + 1, i - j)];
            }
    
    for (int i = 0; i < n; i ++) dp[f(i, i)] = 1;

    function<bool(int, int, int)> check = [&] (int i1, int i2, int l) -> bool {
        int x = lcp[f(i2, i2 - i1)];
        return x < l && s[i1 + x] < s[i2 + x];
    };

    for (int i = 1; i < n; i ++)
        if (s[i] != '0') {
            int cur = 0;
            for (int j = 0; j < n - i; j ++) {
                if (j) {
                    dp[f(i + j, j)] += cur;
                    if (dp[f(i + j, j)] >= mod) dp[f(i + j, j)] -= mod;
                }
                if (i > j) {
                    cur += dp[f(i - 1, j)];
                    if (cur >= mod) cur -= mod;
                    if (check(i - j - 1, i, j + 1)) {
                        dp[f(i + j, j)] += dp[f(i - 1, j)];
                        if (dp[f(i + j, j)] >= mod) dp[f(i + j, j)] -= mod;
                    }
                }
            }
        }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += dp[f(n - 1, i)];
        if (ans >= mod) ans -= mod;
    }
    cout << ans;

    return 0;
}