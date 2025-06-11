#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, x;
    cin >> n >> m;

    vector<int> nums(m);
    for (int i = 0; i < m; i ++)
        cin >> x >> nums[i];
    
    sort(nums.begin(), nums.end(), greater<int>());

    int ans = 0;

    for (int i = 0; i < m; i ++) {
        if (i * (i + 1) / 2 + i % 2 * i / 2 + 1 > n) break;
        ans += nums[i];
    }
    cout << ans;

    return 0;
}