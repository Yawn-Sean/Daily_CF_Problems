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

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, a, b, tot = 0;
    fin >> n >> a >> b;

    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        fin >> nums[i];
        tot += nums[i];
    }

    int inf = 1e9;
    vector<vector<int>> dp(2, vector<int>(tot + 1, inf)), ndp(2, vector<int>(tot + 1, inf));

    dp[0][0] = 0;
    dp[1][0] = 0;

    for (int i = 1; i <= n; i ++) {
        int cost = min(nums[i - 1], nums[i]);
        for (int j = 0; j < 2; j ++) {
            for (int c = 0; c <= tot; c ++) {
                for (int nj = 0; nj < 2; nj ++) {
                    if (c + nums[i] * nj <= tot) {
                        ndp[nj][c + nums[i] * nj] = min(ndp[nj][c + nums[i] * nj], dp[j][c] + (j ^ nj) * cost);
                    }
                }
            }
        }

        for (int j = 0; j < 2; j ++) {
            for (int c = 0; c <= tot; c ++) {
                dp[j][c] = ndp[j][c];
                ndp[j][c] = inf;
            }
        }
    }

    int cost = inf;
    for (int j = 0; j < 2; j ++) {
        for (int c = 0; c <= tot; c ++) {
            if (c <= a && tot - c <= b) {
                cost = min(cost, dp[j][c]);
            }
        }
    }

    fout << (cost < inf ? cost : -1);

    return 0;
}