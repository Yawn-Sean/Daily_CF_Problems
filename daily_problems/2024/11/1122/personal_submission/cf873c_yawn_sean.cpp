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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < m; j ++)
            cin >> grid[i][j];
    
    int ans = 0, cnt = 0;
    vector<int> acc(n + 1, 0);

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++)
            acc[j + 1] = acc[j] + grid[j][i];

        int res = 0, chosen_idx = 0, idx = 0;
        for (int j = 0; j < n; j ++) {
            if (grid[j][i]) {
                int v = acc[min(j + k, n)] - acc[j];
                if (v > res) {
                    res = v;
                    chosen_idx = idx;
                }
                idx ++;
            }
        }
        ans += res;
        cnt += chosen_idx;
    }

    cout << ans << ' ' << cnt;

    return 0;
}