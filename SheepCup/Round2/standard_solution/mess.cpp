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

    int mod = 1e9 + 7;
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<long long> acc1(n + 1, 0), acc2(n + 1, 0);

    for (int i = 0; i < n; i ++) {
        acc1[i + 1] = acc1[i] + nums[i];
        acc2[i + 1] = acc2[i] + 1ll * nums[i] * (nums[i] - 1) / 2;
    }

    vector<int> f(100002, 1);
    for (int i = 1; i <= 100001; i ++)
        f[i] = 1ll * i * f[i - 1] % mod;
    
    for (int i = 0; i < q; i ++) {
        long long l, r;
        cin >> l >> r;

        int pl = lower_bound(acc1.begin(), acc1.end(), l) - acc1.begin();
        int pr = upper_bound(acc1.begin(), acc1.end(), r) - acc1.begin();
        pr --;
        if (pl > pr) cout << "0\n";
        else {
            long long ans = 1ll * (r - l) * (r - l + 1) / 2 - (acc2[pr] - acc2[pl] + (acc1[pl] - l) * (acc1[pl] - l + 1) / 2 + (r - acc1[pr]) * (r - acc1[pr] - 1) / 2);
            cout << ans % mod * (mod + 1) / 2 % mod * f[r - l + 1] % mod << '\n';
        }
    }

    return 0;
}