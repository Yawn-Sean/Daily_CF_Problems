#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int vis[N][2][2];
void solve(){
    int n,m,h;cin>>n>>m>>h;
    vector<int>st(n+1);
    for(int i=0,u;i<h;i++){
        cin>>u;
        st[u]=1;
    }
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<=n;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)vis[i][j][k]=1e18;
    vis[1][0][0]=0,vis[n][1][0]=0;
    // priority_queue<vector<int>>pq;
    // pq.push({0,1,0,0});
    // pq.push({0,n,1,0});
    priority_queue<pair<int,int>>pq;
    pq.push({0,1*100});
    pq.push({0,n*100+10});
    while(pq.size()){
        auto _=pq.top();pq.pop();
        // int dis=-_[0],a=_[1],b=_[2],c=_[3];
        int dis=-_.first,a=_.second/100,b=_.second%100/10,c=_.second%10;
        if(dis!=vis[a][b][c])continue;
        if(st[a])c=1;
        for(auto&[v,w]:g[a]){
            int tm=dis+(c?w/2:w);
            if(tm<vis[v][b][c]){
                vis[v][b][c]=tm;
                pq.push({-tm,v*100+10*b+c});
            }
        }
    }
    int res=1e18;
    for(int i=1;i<=n;i++){
        for(int k1=0;k1<2;k1++){
            for(int k2=0;k2<2;k2++){
                res=min({res,max(vis[i][0][k1],vis[i][1][k2])});
            }
        }
    }
    if(res>=1e18)cout<<-1<<'\n';
    else cout<<res<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}