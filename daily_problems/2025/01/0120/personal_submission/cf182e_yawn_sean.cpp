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

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> rects(n);
    for (auto &[x, y]: rects) cin >> x >> y;

    vector<vector<int>> dp(2 * n + 1, vector<int>(l + 1, 0));
    dp[2 * n][0] = 1;

    int mod = 1e9 + 7;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    for (int i = 0; i <= l; i ++) {
        for (int old = 0; old <= 2 * n; old ++) {
            for (int idx = 0; idx < n; idx ++) {
                if (old / 2 != idx) {
                    int v = (old == 2 * n ? 0 : (old & 1 ? rects[old / 2].second : rects[old / 2].first));

                    if ((v == 0 || rects[idx].first == v) && i + rects[idx].first <= l)
                        add(dp[idx * 2 + 1][i + rects[idx].first], dp[old][i]);
                    if (rects[idx].first != rects[idx].second && (v == 0 || rects[idx].second == v) && i + rects[idx].second <= l)
                        add(dp[idx * 2][i + rects[idx].second], dp[old][i]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 2 * n; i ++)
        add(ans, dp[i][l]);
    cout << ans;

    return 0;
}