#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mod = 1e9 + 7;
    cin >> n;

    vector<int> to_pos(n);
    for (auto &v: to_pos)
        cin >> v, v --;
    
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i ++) {
        dp[i + 1] = dp[i] + dp[i];
        if (dp[i + 1] >= mod) dp[i + 1] -= mod;

        dp[i + 1] -= dp[to_pos[i]];
        if (dp[i + 1] < 0) dp[i + 1] += mod;

        dp[i + 1] += 2;
        if (dp[i + 1] >= mod) dp[i + 1] -= mod;
    }
    cout << dp[n];

    return 0;
}