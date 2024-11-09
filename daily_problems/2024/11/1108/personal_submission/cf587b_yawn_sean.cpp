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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, mod = 1e9 + 7;
    long long l;
    cin >> n >> l >> k;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    if (k == 1) {
        cout << l % mod;
        return 0;
    }

    vector<int> st_range(n);
    iota(st_range.begin(), st_range.end(), 0);
    sort(st_range.begin(), st_range.end(), [&](int i, int j) {return nums[i] < nums[j];});

    int ans = 0;
    vector<int> dp(n * k, 0);

    for (int i = 0; i < k; i ++) {
        int pt = 0, cur = 0;
        for (auto &j: st_range) {
            int idx = i * n + j;
            if (i == 0) dp[idx] = 1;
            else {
                while (pt < n && nums[st_range[pt]] <= nums[j]) {
                    cur += dp[(i - 1) * n + st_range[pt]];
                    if (cur >= mod) cur -= mod;
                    pt ++;
                }
                dp[idx] = cur;
            }
            long long times = l / n - i;
            if (l % n > j) times ++;

            if (times > 0) {
                ans += times % mod * dp[idx] % mod;
                if (ans >= mod) ans -= mod;
            }
        }
    }
    
    cout << ans;

    return 0;
}