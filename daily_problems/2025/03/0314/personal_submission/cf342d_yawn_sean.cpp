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

    vector<vector<int>> note(3, vector<int>(n, 0));
    int x, y;

    for (int i = 0; i < 3; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j ++) {
            if (s[j] == 'X') note[i][j] = 1;
            else if (s[j] == 'O') {
                note[i][j] = 2;
                x = i, y = j;
            }
        }
    }

    vector<int> dirs = {-1, 0, 1, 0, -1};
    vector<pair<int, int>> chosen;

    for (int i = 0; i < 4; i ++) {
        int dx = dirs[i], dy = dirs[i + 1];
        bool flg = true;

        for (int j = 1; j < 3; j ++) {
            int vx = x  + dx * j, vy = y + dy * j;
            if (!(vx >= 0 && vx < 3 && vy >= 0 && vy < n && note[vx][vy] == 0)) {
                flg = false;
            }
        }

        if (flg) chosen.emplace_back(dx, dy);
    }

    int k = chosen.size(), ans = 0, mod = 1e9 + 7;

    for (int msk = 1; msk < (1 << k); msk ++) {
        int c = -1;
        for (int i = 0; i < k; i ++) {
            if (msk >> i & 1) {
                c = -c;
                auto &[dx, dy] = chosen[i];
                for (int j = 1; j < 3; j ++) {
                    note[x + dx * j][y + dy * j] = 1;
                }
            }
        }

        vector<int> dp(8, 0), ndp(8, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i ++) {
            int must = 0;
            for (int j = 0; j < 3; j ++) {
                if (note[j][i]) {
                    must |= 1 << j;
                }
            }

            for (int v0 = 0; v0 < 8; v0 ++) {
                for (int v1 = 0; v1 < 8; v1 ++) {
                    if ((v1 & must) == 0 && (v0 & v1) == 0 && (v0 & must) == 0 && (7 - v1 - must - v0) % 3 == 0) {
                        ndp[v1] += dp[v0];
                        if (ndp[v1] >= mod) ndp[v1] -= mod;
                    }
                }
            }

            for (int j = 0; j < 8; j ++)
                dp[j] = ndp[j], ndp[j] = 0;
        }

        ans += c * dp[0];
        if (ans >= mod) ans -= mod;
        if (ans < 0) ans += mod;

        for (int i = 0; i < k; i ++) {
            if (msk >> i & 1) {
                auto &[dx, dy] = chosen[i];
                for (int j = 1; j < 3; j ++) {
                    note[x + dx * j][y + dy * j] = 0;
                }
            }
        }
    }

    cout << ans;

    return 0;
}