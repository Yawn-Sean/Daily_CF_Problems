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

    int n, x, k;
    cin >> n >> x >> k;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    sort(nums.begin(), nums.end());

    long long ans = 0;
    for (auto &v: nums) {
        int l = (v - 1) / x + k;
        ans += lower_bound(nums.begin(), nums.end(), 1ll * (l + 1) * x) - lower_bound(nums.begin(), nums.end(), max((long long)v, 1ll * l * x));
    }
    cout << ans;

    return 0;
}