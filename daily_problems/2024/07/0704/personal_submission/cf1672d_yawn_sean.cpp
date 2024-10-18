#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        
        vector<int> nums1(n), nums2(n);
        for (auto &x: nums1) cin >> x;
        for (auto &x: nums2) cin >> x;

        vector<int> saved(n + 1);
        int pt = 0;

        for (auto &num: nums1) {
            if (num == nums2[pt]) pt ++;
            else saved[num] ++;
            while (pt < n && pt > 0 && nums2[pt] == nums2[pt-1] && saved[nums2[pt]])
                saved[nums2[pt]] --, pt ++;
        }

        cout << (pt == n ? "YES\n" : "NO\n");
    }

    return 0;
}