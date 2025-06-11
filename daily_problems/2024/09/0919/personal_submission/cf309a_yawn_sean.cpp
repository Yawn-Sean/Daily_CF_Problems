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

    int n, l, t;
    cin >> n >> l >> t;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    t *= 2;
    int d = t % l;
    double ans = 1.0 * n * (n - 1) * (t / l);

    for (int i = 0; i < n; i ++)
        nums.emplace_back(nums[i] + l);
    
    for (int i = 0; i < n; i ++)
        ans += upper_bound(nums.begin(), nums.end(), nums[i] + d) - nums.begin() - 1 - i;
    
    cout << setprecision(20) << ans / 4 << '\n';

    return 0;
}