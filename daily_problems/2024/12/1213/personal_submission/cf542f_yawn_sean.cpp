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

    int n, T;
    cin >> n >> T;

    vector<vector<int>> items(T);
    for (int i = 0; i < n; i ++) {
        int t, q;
        cin >> t >> q;
        items[T - t].emplace_back(q);
    }

    int inf = 1e9;
    vector<int> dp(n + 1, -inf), ndp(n + 1, -inf);
    dp[0] = 0, dp[1] = 0;

    for (int i = 0; i < T; i ++) {
        sort(items[i].begin(), items[i].end(), [&] (int x, int y) {return x > y;});

        for (int j = 0; j <= n; j ++) {
            int cur = 0;
            for (int k = 0; k <= items[i].size(); k ++) {
                if (k > j)
                    break;
                int nj = min(n, 2 * (j - k));
                ndp[nj] = max(ndp[nj], dp[j] + cur);
                if (k < items[i].size())
                    cur += items[i][k];
            }
        }

        for (int j = 0; j <= n; j ++)
            dp[j] = ndp[j], ndp[j] = -inf;
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}