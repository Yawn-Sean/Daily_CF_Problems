/*
    Bonelight * v *
    20241023：CF,Goodnight
    登神长阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());

    for(int i = 0; i < m; i ++){
        int x,y; cin >> x >> y;
        g[x].push_back(y);
    }

    vector<int> vis(n + 1);
    function<void(int)> dfs = [&](int o){
        if(vis[o]) return;
        vis[o] = 1;
        for(auto p:g[o]) if(!vis[p]) { 
            dfs(p);
        }
        cout << o << ' ';
    };

    for(int i = 1; i <= n; i ++) dfs(i);
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
