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

    int n, q;
    cin >> n >> q;

    vector<int> nums1(n), nums2(n);
    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;

    vector<int> p1(n), p2(n);
    for (int i = 1; i < n; i ++) {
        p1[i] = (nums1[i] % 2 == nums1[i-1] % 2 ? p1[i-1] : i);
        p2[i] = (nums2[i] % 2 == nums2[i-1] % 2 ? p2[i-1] : i);
    }

    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -- , y1 -- , x2 -- , y2 --;
        cout << (p1[x1] == p1[x2] && p2[y1] == p2[y2] ? "YES\n" : "NO\n");
    }

    return 0;
}