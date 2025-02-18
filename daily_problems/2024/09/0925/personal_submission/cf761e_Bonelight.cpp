/*
    Bonelight * v *
    20240925:
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for(int i = 0; i < n - 1; i ++){
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1; i <= n; i ++) if(g[i].size() > 4) {cout << "NO" << endl; return;}
    
    vector<pii> ans(n + 1);
    vector<pii> dic = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1},
    };

    cout << "YES" << endl;
    function<void(int,int,int,int,int,int)> dfs 
        = [&](int o, int fa, int d, int f, int x, int y){
        int t = 0;
        for(auto p:g[o]) if(p != fa){
            if(t == f) t ++;
            auto [dx,dy] = dic[t % 4];
            int nx = x + dx * d, ny = y + dy * d;
            ans[p] = {nx,ny};
            dfs(p,o,d/2,(t + 2) % 4,nx,ny);
            t ++;
        }
    };  
    ans[1] = {0,0};
    dfs(1,-1,INF,0,0,0);

    for(int i = 1; i <= n; i ++){
        auto[x,y] = ans[i];
        // cout << i << endl;
        cout << x << ' ' << y << endl;
    } 
    
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
