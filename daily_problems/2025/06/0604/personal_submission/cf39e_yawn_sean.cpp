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
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long p(int i, int j) {
    long long res = 1;
    for (int k = 0; k < j; k ++)
        res *= i;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    vector<vector<int>> dp(32, vector<int>(100000, -1));

    for (int i = 1; i < 32; i ++) {
        for (int j = 1; j < 100000; j ++) {
            if (dp[i][j - 1] == 0 || p(j, i) >= n) dp[i][j] = 0;
        }
    }

    if (dp[1].back() == -1) dp[1].back() = (n - a) & 1;

    for (int i = 1; i < 32; i ++) {
        if (dp[i - 1][1] == 2 || (1 << i) >= n) {
            dp[i][1] = 2;
        }
    }

    for (int i = 30; i > 0; i --) {
        for (int j = 100000 - 2; j > 0; j --) {
            if (dp[i][j] == -1) {
                if (dp[i + 1][j] == 1 || dp[i][j + 1] == 1)
                    dp[i][j] = 0;
                else dp[i][j] = 1;
            }
        }
    }

    vector<string> ans = {"Masha", "Stas", "Missing"};
    cout << ans[dp[b][a]];

    return 0;
}