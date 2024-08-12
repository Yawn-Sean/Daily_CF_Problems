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

    vector<int> nums(n);
    for (auto &num: nums) cin >> num;

    sort(nums.begin(), nums.end());

    int l = 0, r = 1, ans = 0, val = 0;
    long long cur;

    while (l < n) {
        while (r < n && cur + 1ll * (nums[r] - nums[r - 1]) * (r - l) <= k)
            cur += (nums[r] - nums[r - 1]) * (r - l), r ++;
        if (r - l > ans)
            ans = r - l, val = nums[r - 1];
        cur -= nums[r - 1] - nums[l], l ++;
    }
    cout << ans << ' ' << val << '\n';

    return 0;
}