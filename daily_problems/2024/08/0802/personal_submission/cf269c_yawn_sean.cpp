#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> us, vs, ws, tot_flow(n);
    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        us.emplace_back(u);
        vs.emplace_back(v);
        ws.emplace_back(w);
        path[u].emplace_back(i);
        path[v].emplace_back(i);
        tot_flow[u] += w;
        tot_flow[v] += w;
    }

    for (int i = 0; i < n; i ++)
        tot_flow[i] /= 2;
    
    vector<int> ans(m, -1), stk = {0};

    while (stk.size()) {
        int u = stk.back();
        stk.pop_back();
        for (auto &i: path[u]) {
            if (ans[i] == -1) {
                int v = us[i] + vs[i] - u;
                ans[i] = (us[i] == u ? 0 : 1);
                tot_flow[v] -= ws[i];
                if (tot_flow[v] == 0 && v != n - 1)
                    stk.emplace_back(v);
            }
        }
    }

    for (auto &x: ans) cout << x << '\n';

    return 0;
}