#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums1(n);
    for (auto &v: nums1) cin >> v;

    int m;
    cin >> m;

    vector<int> nums2(m);
    for (auto &v: nums2) cin >> v;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int inf = 2e9 + 1000, p1 = 0, p2 = 0, ans1 = 3 * n, ans2 = 3 * m;

    while (p1 < n || p2 < m) {
        int cur = inf;
        if (p1 < n) cur = min(cur, nums1[p1]);
        if (p2 < m) cur = min(cur, nums2[p2]);

        while (p1 < n && nums1[p1] == cur) p1 ++;
        while (p2 < m && nums2[p2] == cur) p2 ++;

        int v1 = 2 * p1 + 3 * (n - p1), v2 = 2 * p2 + 3 * (m - p2);

        if (v1 - v2 > ans1 - ans2) ans1 = v1, ans2 = v2;
    }

    cout << ans1 << ':' << ans2;

    return 0;
}
