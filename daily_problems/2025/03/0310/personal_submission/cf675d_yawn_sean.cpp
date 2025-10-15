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
#include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!

pair<int, int> op1(pair<int, int> x, pair<int, int> y) {
    return max(x, y);
}

pair<int, int> e1() {
    return {-1, 0};
}

pair<int, int> op2(pair<int, int> x, pair<int, int> y) {
    return min(x, y);
}

pair<int, int> e2() {
    return {(int)2e9, 0};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    map<int, int> mp;
    for (auto &v: nums) cin >> v, mp[v] = 0;

    int pt = 0;
    for (auto &[k, v]: mp)
        v = pt ++;
    
    atcoder::segtree<pair<int, int>, op1, e1> seg_ma(n);
    atcoder::segtree<pair<int, int>, op2, e2> seg_mi(n);

    int p;

    p = mp[nums[0]];
    seg_ma.set(p, {p, 0});
    seg_mi.set(p, {p, 0});

    for (int i = 1; i < n; i ++) {
        int p = mp[nums[i]];
        cout << nums[max(seg_ma.prod(0, p).second, seg_mi.prod(p, n).second)] << ' ';
        seg_ma.set(p, {p, i});
        seg_mi.set(p, {p, i});
    }

    return 0;
}