#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    int l = 0, r = 2e9;
    vector<int> dp(n, 1);
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (abs(nums[i] - nums[j]) <= 1ll * m * (i - j)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        if (*max_element(dp.begin(), dp.end()) + k >= n) r = m - 1;
        else l = m + 1;
        fill(dp.begin(), dp.end(), 1);
    }
    cout << l;

    return 0;
}