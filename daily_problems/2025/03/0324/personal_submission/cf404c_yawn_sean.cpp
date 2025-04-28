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

    vector<vector<int>> tmp(n);
    for (int i = 1; i <= n; i ++) {
        int d;
        cin >> d;
        tmp[d].emplace_back(i);
    }

    if (tmp[0].size() != 1) cout << -1;
    else {
        for (int i = 1; i < n; i ++) {
            if (tmp[i].size() > tmp[i - 1].size() * (i == 1 ? k : k - 1)) {
                return cout << -1, 0;
            }
        }

        cout << n - 1 << '\n';
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < tmp[i].size(); j ++) {
                cout << tmp[i - 1][j / (i == 1 ? k : k - 1)] << ' ' << tmp[i][j] << '\n';
            }
        }
    }

    return 0;
}