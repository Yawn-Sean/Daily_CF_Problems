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

    int t;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for (int i = 0; i < n; i ++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j ++) {
                grid[i][j] = s[j] - '0';
            }
        }

        int ans = n * m;
        vector<int> cnt(m, 0), calc(m, 0);

        for (int i = 0; i <= n - 5; i ++) {
            for (int j = 0; j < m; j ++)
                cnt[j] = 0;
            
            for (int j = i + 1; j < i + 4; j ++)
                for (int k = 0; k < m; k ++)
                    cnt[k] += grid[j][k];
            
            for (int j = i + 4; j < n; j ++) {
                for (int k = 0; k < m; k ++)
                    calc[k] = cnt[k];
                
                for (int k = 1; k < m; k ++)
                    calc[k] += 2 - grid[i][k] - grid[j][k];
                
                for (int k = 1; k < m; k ++)
                    calc[k] += calc[k - 1];
                
                int cur = n * m;
                for (int k = m - 1; k >= 3; k --) {
                    cur = min(cur, calc[k - 1] + j - i - 1 - cnt[k]);
                    ans = min(ans, cur - calc[k - 3] + j - i - 1 - cnt[k - 3]);
                }

                for (int k = 0; k < m; k ++)
                    cnt[k] += grid[j][k];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}