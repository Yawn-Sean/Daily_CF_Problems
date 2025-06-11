#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;

    vector<long long> pref(n, 0), suff(n, 0);
    for (int i = 0; i < n; i ++) {
        if (i) pref[i] = pref[i - 1];
        if (i % m == m - 1) pref[i] += nums[i - m + 1];
    }

    for (int i = n - 1; i >= 0; i --) {
        if (i + 1 < n) suff[i] = suff[i + 1];
        if ((n - 1 - i) % m == m - 1) suff[i] += nums[i + m - 1];
    }

    long long ans = 1e18;
    for (int i = 0; i < n; i ++) {
        long long res = 0;
        res += 1ll * (i + 1) / m * nums[i] - pref[i];
        res += suff[i] - 1ll * (n - i) / m * nums[i];

        int left = (i + 1) / m * m, right = n - 1 - (n - i) / m * m;

        if (right - left < m) {
            if (left <= right) res += nums[max(right, i)] - nums[min(left, i)];
            ans = min(ans, res);
        }
    }
    cout << ans * 2;

    return 0;
}