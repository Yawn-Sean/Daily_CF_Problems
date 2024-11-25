#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector <int> sz(n);
    for (int i = 0, u; i < 2*k; ++ i){
        cin >> u;
        u -= 1;
        sz[u] = 1;
    }
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long res = 0;
    auto dfs = [&](auto &&self, int u, int presor)->void{
        for (auto &v : g[u]){
            if (v == presor) continue;
            self(self, v, u);
            sz[u] += sz[v];
            res += min(sz[v], 2*k-sz[v]);
        }
    };
    dfs(dfs, 0, -1);

    cout << res << "\n";
}
