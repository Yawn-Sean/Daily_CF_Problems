#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>>v(m);
    vector<int>res(n+1,1);
    for(auto&[x,y]:v)cin>>x>>y;
    for(int i=0;i<m;i++){
        auto [xi,yi]=v[i];
        for(int j=i+1;j<m;j++){
            auto [xj,yj]=v[j];
            if(yi==yj)continue;
            if(xi==xj&&xi>0&&xi<=n){
                int cnt=2;
                for(int k=j+1;k<m;k++){
                    auto[xk,yk]=v[k];
                    if(xk==xi)cnt++;
                }  
                res[xi]=max(res[xi],cnt);
            }else{
                int sy=yj-yi;
                int sx=xj-xi;
                int gd=__gcd(abs(sy),abs(sx));
                sy/=gd;
                sx/=gd;
                if(sy==0)continue;
                if(yi%sy)continue;
                int nx=xi-(yi/sy)*sx;
                if(nx<=0||nx>n)continue;
                int cnt=2;
                for(int k=j+1;k<m;k++){
                    auto[xk,yk]=v[k];
                    if(sy==0)continue;
                    if(yk%sy)continue;
                    if(xk==(nx+(yk/sy)*sx))cnt++;
                } 
                res[nx]=max(res[nx],cnt);
            }
            
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=res[i];
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}