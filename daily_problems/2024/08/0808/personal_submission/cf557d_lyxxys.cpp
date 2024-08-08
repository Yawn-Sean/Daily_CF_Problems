#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> g(n);
    vector <int> sz(n, 1), vis(n), roots;
    for (int i = 0; i < m; ++ i){
        int a, b;
        cin >> a >> b;
        -- a, -- b;
        g[a].push_back(b), g[b].push_back(a);
    }

    function<void(int)>dfs = [&](int x){
        vis[x] = true;
        for (auto &y : g[x]){
            if (vis[y]) continue;
            dfs(y);
            sz[x] += sz[y];
        }
    };

    {
        int c1 = 0, c2 = 0, Max = 0;
        for (int i  = 0; i < n; ++ i){
            if (vis[i]) continue;
            roots.push_back(i);
            dfs(i);
            Max = max(Max, sz[i]);
            if (sz[i]==1) ++ c1;
            if (sz[i]==2) ++ c2;
        }

        if (Max <= 2){
            ll res = 0;
            if (!c2){
                cout << 3 << " ";
                res = 1ll*c1*(c1-1)*(c1-2)/6;
            } else {
                cout << 2 << " ";
                res = 2ll*c2*(c2-1) + 1ll*c1*c2;
            }
            cout << res << "\n";
            return;
        }
    }


    /*
        不是二分图且存在环，一定是奇数环
    */
    vector <int> color(n, -1);
    function<void(int,int,int&,int&)> dfspart = [&](int x, int col, int &C, int &F){
        if (color[x] != -1){
            F += color[x] != col;
            return;
        }
        C += col;
        color[x] = col;
        for (auto &y : g[x]){
            dfspart(y, !col, C, F);
        }
    };

    ll res = 0, ans = 0;
    for (auto &x : roots){
        if (sz[x] <= 2) continue;
        int cnt = 0, fs = 0;
        dfspart(x, 0, cnt, fs);
        ans += fs/2;
        res += 1ll*cnt*(cnt-1)/2;
        cnt = sz[x] - cnt;
        res += 1ll*cnt*(cnt-1)/2;
    }
    if (ans){
        cout << 0 << " " << ans << "\n";
    } else {
        cout << 1 << " " << res << "\n";
    }
}
