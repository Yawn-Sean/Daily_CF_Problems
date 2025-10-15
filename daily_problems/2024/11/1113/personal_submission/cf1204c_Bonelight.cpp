/*
    Bonelight * v *
    20241113：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>

void solve(){
    int n; cin >> n;
    int st = 0;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> du(n + 1), vis(n + 1);
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        if(x == 0) st = i;
        else g[x].push_back(i), du[x] ^= 1, du[i] ^= 1;
    }

    if(n % 2 == 0) return void(cout << "NO" << endl);

    function<void(int)> BOOM = [&](int o){
        if(vis[o]) return;
        vis[o] = 1;
        cout << o << endl;
        for(auto p:g[o]){
            BOOM(p);
        }
    };
    
    function<void(int,int)> dfs = [&](int o, int fa){
        for(auto p:g[o]){
            dfs(p,o);
        }
        if(!du[o]){
            if(o != st) du[fa] ^= 1;
            BOOM(o);
        }
    };
    cout << "YES" << endl;
    dfs(st,0);
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; 
    while(T --){
        solve();
    }
}
