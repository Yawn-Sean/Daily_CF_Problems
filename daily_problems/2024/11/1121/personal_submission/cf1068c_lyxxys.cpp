#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){  // 模板类无法处理 long double 问题
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
/*
    颜色连接，水平和垂直
*/
void solve(){
    using ary2 = array<int,2>;

    int n, m;
    cin >> n >> m;
    vector <vector<ary2>> g(n);
    vector <int> loc(n);
    int base = 1e6;
    for (int i = 0; i < n; ++ i){
        int x = i+1, y = base;
        g[i].push_back({x, y});
        loc[i] = base;
        base -= 200;
    }

    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        if (u > v) swap(u, v);
        u -= 1, v -= 1;
        loc[u] -= 1;
        g[u].push_back({u+1, loc[u]});
        g[v].push_back({v+1, loc[u]});
    }

    for (int i = 0; i < n; ++ i){
        cout << g[i].size() << "\n";
        for (auto &it : g[i]){
            cout << it[0] << " " << it[1] << "\n";
        }
    }
}
