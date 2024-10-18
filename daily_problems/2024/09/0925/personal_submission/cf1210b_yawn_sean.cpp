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

    vector<long long> nums1(n);
    vector<int> nums2(n);
    map<long long, int> mp;

    for (auto &x: nums1) cin >> x, mp[x] ++;
    for (auto &x: nums2) cin >> x;

    vector<int> used(n, 0);
    long long ans = 0;

    for (auto &[k, v]: mp) {
        if (v > 1) {
            for (int i = 0; i < n; i ++) {
                if (used[i] == 0 && (nums1[i] & k) == nums1[i]) {
                    used[i] = 1;
                    ans += nums2[i];
                }
            }
        }
    }
    cout << ans;

    return 0;
}