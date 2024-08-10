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

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (auto &v: nums) cin >> v;

    for (int i = 1; i < n; i ++)
        nums[i] += nums[i-1];
    
    for (int i = n - 2; i > 0; i --)
        nums[i] = max(nums[i+1], nums[i] - nums[i+1]);
    
    cout << nums[1];

    return 0;
}