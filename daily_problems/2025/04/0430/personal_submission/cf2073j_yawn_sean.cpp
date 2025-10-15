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

    int n;
    cin >> n;

    vector<int> pos(n);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pos[x - 1] = i;
    }

    int inf = 1e9;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int diff = 1; diff < n; diff ++) {
        for (int i = 0; i + diff < n; i ++) {
            int j = i + diff;
            dp[i][j] = inf;
            for (int sep = i; sep < j; sep ++) {
                dp[i][j] = min(dp[i][j], dp[i][sep] + dp[sep + 1][j] + abs(pos[i] - pos[sep + 1]));
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;
}