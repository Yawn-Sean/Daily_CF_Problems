#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>>g[n+1];
    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int>s(n+1);
    for(int i=1;i<=n;i++)cin>>s[i];
    vector<vector<int>>f(n+1,vector<int>(1001,-1));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    f[1][s[1]]=0;
    pq.push({s[1],{1,0}});
    while(pq.size()){
        auto [v,_]=pq.top();pq.pop();
        auto [node,dist]=_;
        for(auto&[i,j]:g[node]){
            if(f[i][v]==-1||f[i][v]>(dist+j*v)){
                f[i][v]=dist+j*v;
                if(s[i]<v){
                    pq.push({s[i],{i,f[i][v]}});
                }else{
                    pq.push({v,{i,f[i][v]}});
                }
            }
        }
    }
    int ans=1e18;
    for(int i=1;i<=1000;i++){
        if(f[n][i]!=-1){
            ans=min(ans,f[n][i]);
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}