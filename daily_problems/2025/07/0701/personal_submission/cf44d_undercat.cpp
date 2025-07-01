#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>x(n),y(n),z(n);
    for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>z[i];
    double ans=1e33;
    auto get=[&](int a,int b)->double{
        int sx=x[a]-x[b],sy=y[a]-y[b],sz=z[a]-z[b];
        return sqrt(sx*sx+sy*sy+sz*sz);
    };
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=min(ans,get(0,i)+get(0,j)+get(i,j));
        }
    }
    cout<<ans/2;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<fixed<<setprecision(10);
    // int t;cin>>t;while(t--)
    solve();
}
