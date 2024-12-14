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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ans;
    for (int i = 1000; i > 1; i --) {
        while (n >= i * (i - 1) / 2) {
            n -= i * (i - 1) / 2;
            ans.emplace_back(i);
        }
    }

    if (ans.size()) {
        for (int i = 0; i < ans.size(); i ++) {
            while (ans[i] --) {
                cout << (char)('a' + i);
            }
        }
    }
    else cout << 'a';

    return 0;
}