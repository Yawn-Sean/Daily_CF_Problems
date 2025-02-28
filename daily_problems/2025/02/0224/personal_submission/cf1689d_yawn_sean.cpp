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

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (auto &s: grid) cin >> s;

        int mx1 = -5000, mi1 = 5000, mx2 = -5000, mi2 = 5000;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 'B') {
                    mx1 = max(mx1, i + j);
                    mi1 = min(mi1, i + j);
                    mx2 = max(mx2, i - j);
                    mi2 = min(mi2, i - j);
                }
            }
        }

        int ans = 5000, x = -1, y = -1;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                int res = max({mx1 - i - j, i + j - mi1, mx2 - i + j, i - j - mi2});
                if (res < ans) {
                    ans = res;
                    x = i, y = j;
                }
            }
        }
        
        cout << x + 1 << ' ' << y + 1 << '\n';
    }

    return 0;
}