#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/lazysegtree"
// #include "atcoder/fenwicktree"
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

    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> nums[i];
    
    vector<int> ans;
    for (int i = n; i > 0; i --) {
        vector<int> nans;

        int c = 0;
        for (auto &x: ans) {
            if (c == nums[i]) {
                nans.emplace_back(i);
                c ++;
            }
            nans.emplace_back(x);
            c += (x >= i + k);
        }

        if (c == nums[i]) nans.emplace_back(i);
        swap(ans, nans);
    }

    for (auto &v: ans) cout << v << ' ';

    return 0;
}