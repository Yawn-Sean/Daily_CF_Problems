#include <bits/stdc++.h>
#define ll long long

int col = 1;
void dfs(int u,std::vector<std::vector<int>> &g,std::vector<int> &cols,int n){
    cols[u] = col;
    for(int v = 0; v < n; ++v){
        if(!g[u][v] && !cols[v])
            dfs(v,g,cols,n);
    }
}

void solve(){
    int n,m,c;
    std::cin >> n >> m >> c;
    std::vector<std::vector<int>> g(n,std::vector<int>(n,0));
    for(int i = 0; i < m; ++i){
        int u,v;
        std::cin >> u >> v;
        u--,v--;
        g[u][v] = 1;
        g[v][u] = 1; 
    }
    std::vector<int> cols(n,0);
    for(int u = 0; u < n; ++u){
        if(!cols[u]){
            dfs(u,g,cols,n);
            col++;
        }
    }

    if(col - 1 > c){
        std::cout << -1 << '\n';
        return;
    }

    for(int u = 0; u < n; ++u){
        for(int v = 0; v < n; ++v){
            if(g[u][v] == 1 && (cols[u] == cols[v])){
                std::cout << -1 << '\n';
                return;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        std::cout << cols[i] << ' ';
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int t;
    // std::cin >> t;
    // while(t--){
        solve();
    // }
    std::cout << std::flush;
    return 0;
}