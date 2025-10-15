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

    int n;
    cin >> n;

    vector<int> ls(n), rs(n);
    for (int i = 0; i < n; i ++)
        cin >> ls[i] >> rs[i];
    
    vector<int> ans(30);
    for (int i = 0; i < 30; i ++) {
        int lazy = 0;
        vector<pair<int, int>> prs;

        int length = 1 << i;
        for (int j = 0; j < n; j ++) {
            int l = ls[j], r = rs[j];
            if (r - l + 1 >= length) lazy ++;
            else {
                l &= length - 1;
                r &= length - 1;
                prs.emplace_back(l, 1);
                prs.emplace_back(r + 1, -1);
                if (l > r) lazy ++;
            }
        }
        prs.emplace_back(0, 0);
        prs.emplace_back(length, 0);
        sort(prs.begin(), prs.end());
        
        int cur = lazy;
        for (auto &[k, v]: prs) {
            if (k == length) break;
            cur += v;
            ans[i] = max(ans[i], cur);
        }
    }

    int q;
    cin >> q;

    while (q --) {
        int v;
        cin >> v;
        cout << ans[__builtin_ctz(v)] << '\n';
    }

    return 0;
}