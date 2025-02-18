#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[202020];
vector<int>g[202020];
int dp[202020][3];
void dfs(int x,int pr){
    for(auto i:g[x]){
        if(i==pr)continue;
        dfs(i,x);
        a[x]+=a[i];
    }
}
void dfs2(int x,int pr){
    dp[x][0]=a[x];
    for(auto i:g[x]){
        if(i==pr)continue;
        dfs2(i,x);
    }
    int ma=-1e16,ma2=-1e16;
    for(auto i:g[x]){
        if(i==pr)continue;
        dp[x][0]=max(dp[x][0],dp[i][0]);
        if(ma<dp[i][0])ma2=ma,ma=dp[i][0];
        else ma2=max(ma2,dp[i][0]);
    }
    dp[x][1]=ma+ma2;
    for(auto i:g[x]){
        if(i==pr)continue;
        dp[x][1]=max(dp[x][1],dp[i][1]);
    }
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,h,i,j,k,x;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    dfs2(1,0);
    if(dp[1][1]<-1e11)cout<<"Impossible";
    else cout<<dp[1][1];
}

