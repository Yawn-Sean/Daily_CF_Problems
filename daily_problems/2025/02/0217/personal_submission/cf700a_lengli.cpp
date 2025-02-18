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
    int n,s,v1,v2,k;
    std::cin>>n>>s>>v1>>v2>>k;
    int rd=(n+k-1)/k;
    double fz=(double)s*(v1+v2);
    double fm=(double)2*v1*(rd-1)+v1+v2;
    double x=fz/fm;
    double res=(double)(s-x)/(double)v1+(double)x/(double)v2;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
