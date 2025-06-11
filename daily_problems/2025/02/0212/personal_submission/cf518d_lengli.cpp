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
    int n,t;
    double p;
    std::cin>>n>>p>>t;
    std::vector<std::vector<double>> f(t+2,std::vector<double> (n+2));
    f[0][0]=1.0;
    for(int i=1;i<=t;i++){
        f[i][0]=f[i-1][0]*(1.0-p);
        for(int j=1;j<=n;j++){
            if(j==n) f[i][j]=f[i-1][j];
            else f[i][j]=f[i-1][j]*(1.0-p);
            f[i][j]+=f[i-1][j-1]*p; 
        }
    }
    double res=0;
    for(int i=1;i<=n;i++) res+=f[t][i]*i;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
