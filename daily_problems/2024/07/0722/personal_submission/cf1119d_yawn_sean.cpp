#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> nums(n);
    for (auto &x: nums) cin >> x;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 1; i ++)
        nums[i] = nums[i+1] - nums[i];
    
    nums[n-1] = 1e18, nums[n-1] ++;
    sort(nums.begin(), nums.end());

    vector<long long> acc(n + 1);
    for (int i = 0; i < n; i ++)
        acc[i+1] = acc[i] + nums[i];

    int q;
    cin >> q;

    while (q --) {
        long long l, r;
        cin >> l >> r;
        long long x = r - l + 1;
        int p = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        cout << acc[p] + x * (n - p) << ' ';
    }

    return 0;
}