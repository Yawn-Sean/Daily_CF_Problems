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

    int t, inf = 1e9 + 100;
    cin >> t;

    while (t --) {
        int n, m;
        cin >> n >> m;

        vector<int> ddls(n), ts(m), ps(m);
        vector<vector<int>> to_finish(n);

        for (auto &x: ddls) cin >> x;

        for (int i = 0; i < m; i ++) {
            int e;
            cin >> e >> ts[i] >> ps[i];
            to_finish[e - 1].emplace_back(i);
        }

        vector<int> ans;
        bool flg = true;

        int cur_time = 0;
        for (int i = 0; i < n; i ++) {
            int cnt = to_finish[i].size();

            vector<int> dp(101, inf);
            vector<vector<int>> pres(101, vector<int>(cnt + 1, -1));
            dp[0] = 0;

            for (int idx = 0; idx < cnt; idx ++) {
                int oid = to_finish[i][idx];
                for (int j = 100; j >= 0; j --) {
                    if (dp[j] < inf) {
                        int nj = min(j + ps[oid], 100);
                        if (dp[nj] > dp[j] + ts[oid]) {
                            dp[nj] = dp[j] + ts[oid];
                            pres[nj][idx + 1] = oid * 101 + j;
                        }
                    }
                }
            }

            if (dp[100] > ddls[i] - cur_time) {
                flg = false;
                break;
            }

            cur_time += dp[100];
            int cur = 100;

            for (int j = cnt; j > 0; j --) {
                if (pres[cur][j] != -1) {
                    ans.emplace_back(pres[cur][j] / 101);
                    cur = pres[cur][j] % 101;
                }
            }
        }
        
        if (flg) {
            cout << ans.size() << '\n';
            for (auto &x: ans)
                cout << x + 1 << ' ';
            cout << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}