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

    vector<int> nums0(n), nums1(n), nums2(n);
    for (auto &v: nums0) cin >> v;
    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;

    int dp0 = nums0[0], dp1 = nums1[0];

    for (int i = 1; i < n; i ++) {
        int tmp = max(dp0 + nums1[i], dp1 + nums0[i]);
        dp1 = max(dp0 + nums2[i], dp1 + nums1[i]);
        dp0 = tmp;
    }
    cout << dp0;

    return 0;
}