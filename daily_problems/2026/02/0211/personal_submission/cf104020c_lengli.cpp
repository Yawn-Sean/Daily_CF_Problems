/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,t,r;
    std::cin>>n>>t>>r;
    double p,q;
    std::cin>>p;
    q=1.0-p;
    std::vector<double> f(n+2),g(n+2,1e18);
    f[0]=0;g[0]=0;
    for(int i=1;i<=n;i++) f[i]=(f[i-1]+p*r+1)/q;
    double ans=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            g[i]=std::min(f[i-j]+g[j]+t,g[i]);
        }
    }

    std::cout<<std::fixed<<std::setprecision(10)<<g[n]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
