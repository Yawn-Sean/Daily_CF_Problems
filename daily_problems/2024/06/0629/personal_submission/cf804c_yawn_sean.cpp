#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> ice_creams(n);
    
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        ice_creams[i].resize(k);
        for (auto &x: ice_creams[i])
            cin >> x, x --;
    }

    vector<vector<int>> path(n);

    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --;
        v --;
        path[u].push_back(v);
        path[v].push_back(u);
    }

    vector<int> ans(m, -1);
    vector<int> used(m);

    function<void(int, int)> dfs = [&] (int u, int p) {
        for (auto &x: ice_creams[u])
            if (ans[x] != -1)
                used[ans[x]] = 1;
        
        int pt = 0;
        for (auto &x: ice_creams[u])
            if (ans[x] == -1) {
                while (used[pt]) pt ++;
                ans[x] = pt;
                used[pt] = 1;
            }
        
        for (auto &x: ice_creams[u])
            used[ans[x]] = 0;

        for (auto &v: path[u])
            if (v != p)
                dfs(v, u);
    };

    dfs(0, -1);

    for (int i = 0; i < m; i ++) 
        ans[i] = (~ans[i] ? ans[i] + 1 : 1);
    
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    for (auto &x: ans) cout << x << ' ';

    return 0;
}