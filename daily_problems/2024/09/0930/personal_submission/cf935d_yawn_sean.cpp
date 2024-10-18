#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(n);
    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;

    int ans = 0, prob = 1, mod = 1e9 + 7;
    int inv2 = quickPow(2, mod - 2, mod), invm = quickPow(m, mod - 2, mod);

    for (int i = 0; i < n; i ++) {
        if (nums1[i]) {
            if (nums2[i]) {
                if (nums1[i] > nums2[i]) {
                    ans += prob;
                    if (ans >= mod) ans -= mod;
                    break;
                }
                else if (nums1[i] < nums2[i]) break;
            }
            else {
                prob = 1ll * prob * invm % mod;
                ans += 1ll * prob * (nums1[i] - 1) % mod;
                if (ans >= mod) ans -= mod;
            }
        }
        else {
            if (nums2[i]) {
                prob = 1ll * prob * invm % mod;
                ans += 1ll * prob * (m - nums2[i]) % mod;
                if (ans >= mod) ans -= mod;
            }
            else {
                prob = 1ll * prob * invm % mod;
                ans += 1ll * prob * (m - 1) % mod * inv2 % mod;
                if (ans >= mod) ans -= mod;
            }
        }
    }
    cout << ans;

    return 0;
}