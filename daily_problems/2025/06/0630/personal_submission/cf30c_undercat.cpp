#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>x(n),y(n),t(n),xb(n);
    vector<double>p(n),dp(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>t[i]>>p[i];
        xb[i]=i;
    }
    sort(xb.begin(),xb.end(),[&](int a,int b){
        return t[a]<t[b];
    });
    double res=0;
    for(int i=0;i<n;i++){
        int xi=x[xb[i]],yi=y[xb[i]],ti=t[xb[i]];
        double pi=p[xb[i]];
        for(int j=0;j<i;j++){
            int xj=x[xb[j]],yj=y[xb[j]],tj=t[xb[j]];
            double pj=p[xb[j]];
            if(((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj))<=(ti-tj)*(ti-tj)){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]+=pi;
        res=max(res,dp[i]);
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<fixed<<setprecision(10);
    // int t;cin>>t;while(t--)
    solve();
}
