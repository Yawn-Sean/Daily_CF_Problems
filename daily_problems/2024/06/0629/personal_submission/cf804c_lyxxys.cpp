#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 300500, inf = 1e9;

void solve(){
    int n, m, res = 0;
    cin >> n >> m;
    vector <int> bok[n+1];
    vector<vector<int>> g(n+1);
    for (int i = 1; i <= n; ++ i){
        int s, x;
        cin >> s;
        if (res < s) res = s;
        while (s--){
            cin >> x;
            bok[i].push_back(x);
        }
    }

    for (int i = 1; i < n; ++ i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    map <int,int> mp;
    vector <int> ans(m+1);
    function<void(int,int)> dfs = [&](int u, int fa){
        mp.clear();
        for (auto &x : bok[u]){
            if (ans[x] != 0) mp[ans[x]] = 1;
        }
        int cnt = 0;
        for (auto &x : bok[u]){
            if (ans[x]) continue;
            while (mp[++ cnt]);
            ans[x] = cnt;
        }
        for (auto &x : g[u])
            if (x != fa)
                dfs(x, u);
    };    
    dfs(1,-1);
    cout << res << "\n";
    for (int i = 1; i <= m; ++ i){
        cout << (ans[i] ? ans[i] : 1) << "\n "[i < m];
    }
} 
 
