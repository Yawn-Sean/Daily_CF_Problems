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
// I came, I divided, I conquered!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums1(n / k), nums2(n / k);
    for (auto &x: nums1) cin >> x;
    for (auto &x: nums2) cin >> x;

    int mod = 1e9 + 7, ans = 1;
    long long v = 1;
    for (int i = 0; i < k - 1; i ++)
        v = v * 10;
    
    auto div = [&] (long long x, int y) -> long long {
        return (x >= 0 ? x / y + 1 : 0);
    };

    for (int i = 0; i < n / k; i ++) {
        ans = (div(v * 10 - 1, nums1[i]) - (div(v * (nums2[i] + 1) - 1, nums1[i]) - div(v * nums2[i] - 1, nums1[i]))) % mod * ans % mod;
    }

    cout << (ans + mod) % mod;

    return 0;
}