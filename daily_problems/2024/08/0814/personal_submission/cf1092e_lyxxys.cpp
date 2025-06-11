#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 33, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> g(n);
    vector <int> dMax(n), vis(n), son1(n), son2(n), d1(n), d2(n), up(n);
    for (int i = 0, u,v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v), g[v].push_back(u);
    }
    function<void(int,int)> dfson = [&](int x, int fa){
        vis[x] = true;
        for (auto &y : g[x]){
            if (y == fa) continue;
            dfson(y, x);
            if (d1[y]+1 > d1[x]){
                d2[x] = d1[x], son2[x] = son1[x];
                d1[x] = d1[y]+1, son1[x] = y;
            } else if (d1[y]+1 > d2[x]){
                d2[x] = d1[y]+1, son2[x] = y;
            }
        }
    };

    int dia = 0;
    function<void(int,int,int&)> dfsroot = [&](int x, int fa, int &core){
        vis[x] = true;
        for (auto &y : g[x]){
            if (y == fa) continue;
            if (y == son1[x]) up[y] = max(d2[x], up[x])+1;
            else up[y] = max(d1[x], up[x])+1;
            dfsroot(y, x, core);
        }
        dia = max(dia, up[x]+d1[x]);
        dMax[x] = max(up[x], d1[x]);
        if (core == -1 || dMax[x] < dMax[core]) core = x;
    };

    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            dfson(i, -1);
        }
    }
    
    fill(vis.begin(), vis.end(), 0);
    vector <int> cores;
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            int core = -1;
            dfsroot(i, -1, core);
            cores.push_back(core);
        }
    }
    if (m == n-1){
        cout << dia << "\n";
        return;
    }

    vector <int> p(cores.size());
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y){
        return dMax[cores[x]] > dMax[cores[y]];
    });

    int ans = max(dia, dMax[cores[p[0]]]+dMax[cores[p[1]]]+1);
    if (p.size() > 2) ans = max(ans, dMax[cores[p[1]]]+dMax[cores[p[2]]]+2);
    cout << ans << "\n";
    for (int i = 1; i < p.size(); ++ i){
        cout << cores[p[0]]+1 << " " << cores[p[i]]+1 << "\n";
    }
}
