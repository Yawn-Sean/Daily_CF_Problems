#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1050, M = 1<<10, mod = 998244353, inf = 1e9;

void solve(){
    int n, q;
    cin >> n >> q;
    vector <vector<int>> g(n+1);
    vector <int> fa(n+1);
    for (int i = 2; i <= n; ++ i){
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    vector <int> dep(n+1), sz(n+1, 1), own(n+1), order, stk = {1};
    iota(own.begin(), own.end(), 0);
    {
        while (!stk.empty()){
            auto x = stk.back();
            stk.pop_back();
            order.push_back(x);
            for (auto &y : g[x]){
                dep[y] = dep[x] + 1;
                stk.push_back(y);
            }
        }
        for (int i = n-1; i > 0; -- i)
            sz[fa[order[i]]] += sz[order[i]];
        for (auto &x : order){
            if (g[x].empty()) continue;
            int core = -1;
            for (auto &y : g[x]){
                if (core==-1 || sz[y] >= sz[core])
                    core = y;
            }
            own[core] = own[x];
        }
    }

    function<int(int,int)> lca = [&](int x, int y){
        while (own[x] != own[y]){
            if (dep[own[x]] < dep[own[y]]) swap(x, y);
            x = fa[own[x]];
        }
        return dep[x] <= dep[y] ? x : y;
    };

    function<int(int,int)> dist = [&](int x, int y){
        return dep[x]+dep[y]-2*dep[lca(x,y)];
    };
    while (q--){
        int a, b, c;
        cin >> a >> b >> c;
        int d1, d2, d3, d = 1e9;
        d1 = dist(a, b), d = min(d, d1);
        d2 = dist(a, c), d = min(d, d2);
        d3 = dist(b, c), d = min(d, d3);
        int ans = (d1+d2+d3 - 2*d)/2 + 1;
        cout << ans << "\n";
    }
}
