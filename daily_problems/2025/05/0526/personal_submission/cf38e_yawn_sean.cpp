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

    int n;
    cin >> n;

    vector<int> xs(n), cs(n);
    for (int i = 0; i < n; i ++)
        cin >> xs[i] >> cs[i];
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int i, int j) {return xs[i] > xs[j];});

    vector<long long> acc(n + 1, 0);
    for (int i = 0; i < n; i ++)
        acc[i + 1] = acc[i] + xs[order[i]];
    
    long long inf = 1e18;
    vector<long long> dp(n + 1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= i; j ++) {
            dp[i + 1] = min(dp[i + 1], dp[j] + cs[order[i]] + acc[i + 1] - acc[j] - 1ll * xs[order[i]] * (i + 1 - j));
        }
    }

    cout << dp[n];

    return 0;
}