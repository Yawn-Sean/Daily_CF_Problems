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

    int n, m, a;
    cin >> n >> m >> a;

    vector<int> nums1(n), nums2(m);

    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int l = 0, r = min(n, m);

    while (l <= r) {
        int mid = (l + r) / 2, cur = 0;
        bool flg = true;
        for (int i = 0; i < mid; i ++) {
            cur += max(nums2[i] - nums1[n - mid + i], 0);
            if (cur > a) {
                flg = false;
                break;
            }
        }
        if (flg) l = mid + 1;
        else r = mid - 1;
    }

    int ans = -a;
    for (int i = 0; i < r; i ++) 
        ans += nums2[i];

    cout << r << ' ' << max(0, ans);

    return 0;
}