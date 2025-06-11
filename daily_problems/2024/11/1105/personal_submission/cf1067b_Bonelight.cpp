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
    int n,k; cin >> n >> k;

    vector<vector<int>> g(n + 1, vector<int>());
    vector<int> vis(n + 1);
    
    for(int i = 1; i <= n - 1; i ++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if(k >= 11 || n == 1) return void(cout << "No" << endl);

    queue<int> q;
    for(int i = 1; i <= n; i ++){
        if(g[i].size() == 1) q.emplace(i), vis[i] = 1;
    }
    int o = -1;
    while(q.size()){
        o = q.front(); q.pop();
        for(auto p:g[o]) if(!vis[p]){
            q.emplace(p);
            vis[p] = 1;
        }
    }

    int st = o;
    q = queue<int>();
    vector<int> val(n + 1, -1);
    q.emplace(o);
    val[o] = 0;

    while(q.size()){
        o = q.front(); q.pop();
        for(auto p:g[o]) if(val[p] == -1){
            q.emplace(p);
            val[p] = val[o] + 1;
        }
        if(g[o].size() != 1 && g[o].size() < 4 - (o == st)){
            return void(cout << "No" << endl);
        }
        if(g[o].size() == 1 && val[o] != k) return void(cout << "No" << endl);
    }
    cout << "Yes" << endl;
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
