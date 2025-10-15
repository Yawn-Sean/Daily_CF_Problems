/*
    Bonelight * v *
    20241101：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>

void solve(){
    int n,x,y; cin >> n >> x >> y;
    vector<vector<int>> g(n + 1, vector<int>());

    for(int i = 0; i < n - 1; i ++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> sz(n + 1, 1), passY(n + 1);
    passY[y] = 1;
    
    function<void(int, int)> dfs = [&](int o, int fa){    
        for(auto p:g[o]) if(p != fa){
            dfs(p,o);
            if(!passY[p]){sz[o] += sz[p];}
            else passY[o] = 1;
        }
    };

    dfs(x,0);
    cout << n * (n - 1) - (sz[x] * sz[y]) << endl;
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
