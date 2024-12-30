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

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    vector<int> ls(5001), rs(5001);

    for (int i = n - 1; i >= 0; i --)
        ls[nums[i]] = i;
    
    for (int i = 0; i < n; i ++)
        rs[nums[i]] = i;
    
    vector<int> dp(n + 1, 0), vis(5001, 0);

    for (int i = 0; i < n; i ++) {
        int r = 0, v = 0;
        
        for (int j = i; j < n; j ++) {
            if (ls[nums[j]] < i) break;

            if (!vis[nums[j]]) {
                vis[nums[j]] = 1;
                v ^= nums[j];
            }

            if (rs[nums[j]] > r)
                r = rs[nums[j]];
            
            if (j == r)
                dp[j + 1] = max(dp[j + 1], dp[i] + v);
        }

        dp[i + 1] = max(dp[i + 1], dp[i]);
        
        for (int j = 0; j <= 5000; j ++)
            vis[j] = 0;
    }
    cout << dp[n];

    return 0;
}