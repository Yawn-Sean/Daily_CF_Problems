/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,x;
    std::cin>>n>>x;
    int D=130;
    std::vector<double> f(D);
    for(int i=0;i<=x;i++) std::cin>>f[i];
    matrix<double> a(D,D);
    for(int i=0;i<D;i++){
        for(int j=0;j<D;j++){
            int t=i^j;
            a[i][j]=t<=x ? f[t] : 0;
        }   
    }
    matrix<double> base(D,1);
    base[0][0]=1;
    a=a^n;
    base=a*base;
    double res=1.0-base[0][0];
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
