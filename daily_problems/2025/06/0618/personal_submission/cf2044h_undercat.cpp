#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
   int n,q;cin>>n>>q;
   vector<vector<int>>g(n+1,vector<int>(n+1));
   for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>g[i][j];
   auto addx=g,addy=g,add=g;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        addx[i][j]=g[i][j]*i;
        addy[i][j]=g[i][j]*j;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)add[i][j]+=add[i-1][j],addx[i][j]+=addx[i-1][j],addy[i][j]+=addy[i-1][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)add[i][j]+=add[i][j-1],addx[i][j]+=addx[i][j-1],addy[i][j]+=addy[i][j-1];
    while(q--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        auto get=[&](auto&v)->int{
            return v[x2][y2]-v[x1-1][y2]-v[x2][y1-1]+v[x1-1][y1-1];
        };
        int res=(y2-y1+1)*get(addx);
        res+=get(addy);
        res+=(-x1*y2+x1*y1-x1-y1+1)*get(add);
        cout<<res<<' ';
    }cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}