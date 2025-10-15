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

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<int> cur(n), cnt(m + 1, 0);
    int ans = 0;

    for (int j = 0; j < m; j ++) {
        for (int i = 0; i < n; i ++) {
            cur[i] = (grid[i][j] == '1' ? cur[i] + 1 : 0);
        }

        for (auto &x: cur) cnt[x] ++;
        
        int c = 0;
        for (int j = m; j >= 0; j --) {
            c += cnt[j];
            ans = max(ans, c * j);
        }

        for (auto &x: cur) cnt[x] --;
    }
    
    cout << ans;

    return 0;
}