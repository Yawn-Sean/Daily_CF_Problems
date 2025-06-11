#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> g;
vector<vector<int>> dp, vis;
string nxt = "DIMA";

int dfs(int x,int y){
    if(dp[x][y] != -1) return dp[x][y];
    if(vis[x][y] == 1){
        cout<<"Poor Inna!";
        exit(0);
    }
    vis[x][y] = 1;
    int res=0;
    vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
    char need = nxt[(nxt.find(g[x][y]) + 1) % 4];
    for(auto &d:dirs){
        int nx=x+d.first, ny=y+d.second;
        if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]==need){
            res = max(res, dfs(nx,ny));
        }
    }
    if(g[x][y]=='A') res++;
    dp[x][y]=res; 
    vis[x][y] = 0;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    g.resize(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    dp.assign(n, vector<int>(m,-1));
    vis.assign(n, vector<int>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='D'){
                ans = max(ans, dfs(i,j));
            }
        }
    }
    if(ans==0) cout<<"Poor Dima!";
    else cout<<ans;
    return 0;
}