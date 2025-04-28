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

    int x;
    cin >> x;

    x ++;

    vector<int> vals;
    while (x) {
        vals.emplace_back(x % 10);
        x /= 10;
    }

    reverse(vals.begin(), vals.end());

    vector<int> dp(10, 0);
    int cnt = 0;

    for (auto &x: vals) {
        for (int i = 9; i > 0; i --)
            dp[i] = dp[i] * 8 + dp[i - 1] * 2;
        dp[0] *= 8;

        for (int i = 0; i < x; i ++)
            dp[cnt + (i == 4 || i == 7)] ++;
        cnt += (x == 4 || x == 7);
    }

    dp[0] --;
    int mod = 1e9 + 7;

    auto dfs = [&] (auto &self, int i, int total) -> int {
        if (total > 9) return 0;

        long long ans = 0;

        if (i < 6) {
            for (int j = 0; j < 10; j ++) {
                if (dp[j]) {
                    dp[j] --;
                    ans += 1ll * (dp[j] + 1) * self(self, i + 1, total + j);
                    dp[j] ++;
                }
            }
        }
        else {
            for (int j = total + 1; j < 10; j ++)
                ans += dp[j];
        }
        return ans % mod;
    };

    cout << dfs(dfs, 0, 0);

    return 0;
}