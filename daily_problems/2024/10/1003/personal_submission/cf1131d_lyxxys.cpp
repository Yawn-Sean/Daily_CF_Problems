#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> g(n+m);
    vector <int> deg(n+m), ans(n+m);
    string s[n];
    for (int i = 0; i < n; ++ i) cin >> s[i];

    dsu uni(n+m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == '='){
                uni.merge(i, j+n);
            }
        }
    }

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == '=') continue;
            int u = uni.root(i), v = uni.root(j+n);
            if (u==v) return cout << "No\n", void();
            if (s[i][j] == '>'){
                g[v].push_back(u);
                deg[u] += 1;
            } else {
                g[u].push_back(v);
                deg[v] += 1;
            }
        }
    }

    int cnt = 0;
    queue <int> Q;
    for (int i = 0; i < n+m; ++ i)
        if (deg[i]==0) Q.push(i), ans[i] = 1;
    
    while (!Q.empty()){
        auto t = Q.front();
        Q.pop();
        cnt += 1;
        for (auto &x : g[t]){
            deg[x] -= 1;
            ans[x] = max(ans[x], ans[t]+1);
            if (deg[x]==0) Q.push(x);
        }
    }
    if (cnt < n+m) cout << "No\n";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; ++ i){
            if (i) cout << " ";
            cout << ans[uni.root(i)];
        }
        cout << "\n";
        for (int i = n; i < n+m; ++ i){
            if (i > n) cout << " ";
            cout << ans[uni.root(i)];
        }
        cout << "\n";
    }
}
