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
    string s;
    cin >> n >> s;

    int total = 1 << 20;
    vector<vector<int>> dp(11, vector<int>(total, 0));
    vector<int> dp_sep(total, 0);

    int ans = 0, mod = 1e9 + 7;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    vector<int> possible(11, 0), npossible(11, 0);
    for (int i = 0; i < n; i ++) {
        int c = s[i] - '0';
        add(dp[0][0], 1);
        possible[0] = 1;

        for (int x = 0; x <= 10; x ++) {
            if (!possible[x]) continue;
            if (x * 2 + c >= 1 && x * 2 + c <= 20) {
                for (int y = 0; y < total; y ++) {
                    add(dp_sep[y | (1 << (x * 2 + c - 1))], dp[x][y]);
                }
            }
        }

        for (int x = 1; x < 20; x ++)
            add(ans, dp_sep[(1 << x) - 1]);
        
        for (int x = 10; x >= 0; x --) {
            if (possible[x]) {
                if (2 * x + c <= 10) {
                    npossible[2 * x + c] = 1;
                    for (int y = 0; y < total; y ++)
                        dp[2 * x + c][y] = dp[x][y];
                }
                if (x || c)
                    for (int y = 0; y < total; y ++) 
                        dp[x][y] = 0;
            }
        }

        for (int x = 0; x < total; x ++) {
            add(dp[0][x], dp_sep[x]);
            dp_sep[x] = 0;
        }

        for (int x = 0; x <= 10; x ++)
            possible[x] = npossible[x], npossible[x] = 0;
    }

    cout << ans;

    return 0;
}