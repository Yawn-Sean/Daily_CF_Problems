
#include <bits/stdc++.h>
using namespace std;

vector<int> color, path;
vector<vector<int>> g;

void opt(int u) {
    color[u] = -color[u];
    path.push_back(u);
}

void dfs(int u, int f) {
    opt(u);
    for(int v: g[u]) {
        if(v != f) dfs(v, u);
    }
    if(u != 0) {
        if(color[u] == 1) {
            opt(f);
        } else {
            opt(f);
            opt(u);
            opt(f);
        }
    } else {
        if(color[u] == 1) {
            // do nothing
        } else {
            int v = g[u][0];
            opt(v);
            opt(u);
            opt(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    color.resize(n);
    for(int i = 0; i < n; i++){
        cin >> color[i];
    }
    g.assign(n, {});
    for(int i = 0; i < n-1; i++){
        int u,v; cin >> u >> v; 
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(all_of(color.begin(), color.end(), [](int c){return c==1;})){
        cout << 1;
        return 0;
    }
    color[0] = -color[0];
    dfs(0, -1);
    for(auto &x: path) x++;
    for(int i = 0; i < (int)path.size(); i++){
        cout << path[i] << (i+1<(int)path.size()?' ':'\n');
    }
    return 0;
}