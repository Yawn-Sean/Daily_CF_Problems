#include<bits/stdc++.h>
using namespace std;
const int N =1010;
const int mod=1e9+7;
#define int long long
vector<pair<int,int>> edge[N];vector<int> v(N);
vector<vector<int>> dp(N,vector<int>(N,1e18+7));
void diji(int n){
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = 1e18+7;
    dp[1][1]=0;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.push({0,1,1});//路径长度，出发点,当前起的车的点
    while(!pq.empty()){
        auto [a,b,c]=pq.top();pq.pop();
        if(dp[b][c]<a)continue;
        for(auto [x,y]:edge[b]){
            int d=a+v[c]*y;
            // int nv=(v[x]>v[c]?x:c);
            int nv=(v[x]<v[c]?x:c);
            if(d<dp[x][nv]){
                dp[x][nv]=d;
                pq.push({d,x,nv});
            }
        }
    }
}
void solve(){
	int n,m;cin>>n>>m;
     for(int i=0; i<N; i++) {
        edge[i].clear();
    }
    v.clear();
    v.resize(N);
    // dp.clear();
    for(int i=1;i<=m;i++){
        int x,y,w;cin>>x>>y>>w;
        edge[x].push_back({y,w});edge[y].push_back({x,w});
    }
    for(int i=1;i<=n;i++)cin>>v[i];
    diji(n);
    int ans=1e18+7;
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[n][i]);
    }
    cout<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)
    {solve();}
    return 0;
}
