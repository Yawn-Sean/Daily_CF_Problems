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
#define VC vector<int>
#define MAT vector<VC>

void solve(){   
    int n,m; cin >> n >> m;
    vector<vector<pii>> g(n + 1, vector<pii>());
    for(int i = 1; i <= n; i ++){
        g[i].emplace_back(i,i);
    }
    for(int i = 1; i <= m; i ++){
        int x,y; cin >> x >> y;
        g[x].emplace_back(n+i,x);
        g[y].emplace_back(n+i,y);
    }

    for(int i = 1; i <= n; i ++){
        cout << g[i].size() << endl;
        for(auto [x,y]:g[i]){
            cout << x << ' ' << y << endl;
        }
    }
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
