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

    vector<long long> nums1(n), nums2(n);
    for (auto &x: nums1) cin >> x;
    for (auto &x: nums2) cin >> x;

    vector<long long> acc1(n + 1, 0), acc2(n + 1, 0);
    for (int i = 0; i < n; i ++) {
        acc1[i + 1] = acc1[i] + nums1[i];
        acc2[i + 1] = acc2[i] + nums2[i];
    }

    vector<long long> dp1(n + 1, 0), dp2(n + 1, 0);
    for (int i = n - 1; i >= 0; i --) {
        dp1[i] = dp1[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2ll * i * nums1[i] + (2ll * n - 1) * nums2[i];
        dp2[i] = dp2[i + 1] - (acc1[n] - acc1[i + 1]) - (acc2[n] - acc2[i + 1]) + 2ll * i * nums2[i] + (2ll * n - 1) * nums1[i];
    }

    long long ans = dp1[0], cur = 0;

    for (int i = 0; i < n; i ++) {
        if (i & 1) {
            cur += 2ll * i * nums2[i] + (2ll * i + 1) * nums1[i];
            ans = max(ans, cur + dp1[i + 1]);
        }
        else {
            cur += 2ll * i * nums1[i] + (2 * i + 1) * nums2[i];
            ans = max(ans, cur + dp2[i + 1]);
        }
    }

    cout << ans;

    return 0;
}