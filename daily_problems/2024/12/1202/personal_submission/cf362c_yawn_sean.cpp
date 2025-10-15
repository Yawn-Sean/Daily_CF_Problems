#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

    int n;
    cin >> n;

    vector<int> perm(n);
    for (auto &x: perm)
        cin >> x;
    
    vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i ++)
        pref[i + 1][perm[i] + 1] = 1;
    
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j < n; j ++) {
            pref[i][j + 1] += pref[i][j];
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j <= n; j ++) {
            pref[i + 1][j] += pref[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            ans += (perm[i] < perm[j]);
        }
    }

    int res = -1, cnt = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < i; j ++) {
            if (perm[i] < perm[j]) {
                int v = 2 * (pref[i][perm[j]] - pref[j + 1][perm[j]] - pref[i][perm[i] + 1] + pref[j + 1][perm[i] + 1]) + 1;
                if (v > res) {
                    res = v;
                    cnt = 1;
                }
                else if (v == res)
                    cnt ++;
            }
        }
    }

    cout << ans - res << ' ' << cnt;

    return 0;
}