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
    int n;
    std::cin>>n;
    std::vector<double> p(n+2);
    for(int i=0;i<=n;i++){
        std::cin>>p[i];
    }
    double res;
    if(~n&1){
        res=p[n/2];
    }
    for(int i=0;i<=(n-1)/2;i++){
        for(int j=n/2+1;j<=n;j++){
            res=std::max(res,(p[j]*(n-2*i)+p[i]*(2*j-n))/(2*j-2*i));
        }
    }
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
