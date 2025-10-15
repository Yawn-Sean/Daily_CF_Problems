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
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

    int n;
    cin >> n;

    vector<int> nums(n * 2);
    vector<int> mp(101);

    for (auto &v: nums)
        cin >> v, mp[v] ++;

    vector<int> order(n * 2);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&] (int i, int j) {
        return (mp[nums[i]] < mp[nums[j]] ? 1 : (mp[nums[i]] == mp[nums[j]] && nums[i] < nums[j]));
    });

    vector<int> cols(n * 2, 1);
    set<int> st1, st2;

    for (int i = 0; i < n * 2; i ++) {
        if (i & 1) cols[order[i]] = 2, st2.insert(nums[order[i]]);
        else st1.insert(nums[order[i]]);
    }

    cout << st1.size() * st2.size() << '\n';
    for (auto &x: cols) cout << x << ' ';

    return 0;
}