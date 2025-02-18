#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> f(n+1, 1), deg(n+1);
    vector <vector <int>> g(n+1);
    for (int i = 0, a,b; i < m; ++ i){
        cin >> a >> b;
        ++ deg[a], ++ deg[b];
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long res = 0;
    for (int i = 1; i <= n; ++ i){
        for (auto &x : g[i]){
            if (x > i){
                f[x] = max(f[x], f[i]+1);
            }
        }
        res = max(res, 1ll*f[i]*deg[i]);
    }

    cout << res << "\n";
}
 
