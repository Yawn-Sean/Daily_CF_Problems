#include<bits/stdc++.h>
using namespace std;
int dp[101][101][30];
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>>g(n);
    for(int i=0,u,v;i<m;i++){
        char c;cin>>u>>v>>c;u--;v--;
        g[u].push_back({v,c-'a'});
    }
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)for(int j=0;j<30;j++)dp[i][i][j]=0;
    auto dfs=[&](auto&&dfs,int i,int j,int k)->int{
        int&res=dp[i][j][k];
        if(res!=-1)return res;
        for(auto&[x,y]:g[i]){
            if(y<k)continue;
            if(dfs(dfs,j,x,y)==0)return res=1;
        }
        return res=0;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dfs(dfs,i,j,0)==0)cout<<"B";
            else cout<<"A";
        }cout<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}
