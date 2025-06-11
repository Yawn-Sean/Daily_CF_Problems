#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    x -= 1, y -= 1;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++ i){
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> vis(n), sz(n, 1);

    auto dfs = [&](auto &&self, int u, int fa)->void{
        for (auto &v : g[u]){
            if (v==fa) continue;
            self(self, v, u);
            sz[u] += sz[v];
            vis[u] |= vis[v];
        }
    };
    vis[y] = 1;
    dfs(dfs, x, -1);
    int sz1 = sz[x], sz2 = sz[y];
    for (auto &v : g[x]){
        if (vis[v]){
            sz1 -= sz[v];
            break;
        }
    }

    long long ans = 1ll*n*(n-1) - 1ll*sz1*sz2;
    cout << ans << "\n";
}

