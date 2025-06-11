#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+5, inf = 1e9;
struct Node {
    int son, id;
};
void solve(){
    int n;
    cin >> n;
    vector<vector<Node>> g(n+1);
    vector <int> sz(n+1);
    for (int i = 1; i < n; ++ i){
        int u, v;
        cin >> u >> v;
        g[u].push_back({v,i}), g[v].push_back({u,i});
    }
    //要断n/3-1 次分支
    vector <int> ans;
    function<void(int,int)> dfs = [&](int x, int fa){
        sz[x] = 1;
        for (auto &[son, id]: g[x]){
            if (son == fa) continue;
            dfs(son, x);
            if (sz[son]==0) ans.push_back(id);
            sz[x] += sz[son];
        }
        if (sz[x]==3) sz[x] = 0;
    };
    dfs(1, -1);
    int len = ans.size();
    if (3*(len+1) == n){
        cout << len << "\n";
        for (auto &x : ans) cout << x << " ";
        cout << "\n";
    } else cout << -1 << "\n";
}
