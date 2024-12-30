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
    int a,b;
    std::cin>>a>>b;
    if(!b){
        std::cout<<1<<"\n";
        return;
    }
    if(!a){
        std::cout<<"0.5"<<"\n";
        return;
    }
    double res=0;
    if(b*4>a) res=(2.0*b+(1.0*a)/4.0)/(4.0*b);
    else res=1.0-(double)b/a;
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
