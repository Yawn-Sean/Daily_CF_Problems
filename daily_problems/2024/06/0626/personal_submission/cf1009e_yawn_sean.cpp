#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, mod = 998244353;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    vector<int> pow2(n+1, 1);
    for (int i = 0; i < n; i ++) {
        pow2[i+1] = pow2[i] * 2;
        if (pow2[i+1] >= mod) pow2[i+1] -= mod;
    }

    int ans = nums[n-1];
    for (int i = 0; i < n - 1; i ++) {
        ans += 1ll * nums[i] * (pow2[n-i-1] + 1ll * (n - i - 1) * pow2[n-i-2] % mod) % mod;
        if (ans >= mod) ans -= mod;
    }
    cout << ans << '\n';

    return 0;
}