/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define f64 double

const f64 pi=acos(-1.0);

void solve(){
    f64 a,b;
    std::cin>>a>>b;

    f64 x=4*sin(pi/4)*b*b;
    
    if(a>=x){
        std::cout<<std::fixed<<std::setprecision(10)<<x<<"\n";
    }else{
        f64 t=asin(a/4/b/b)/2;
        f64 v=b*sin(t);
        std::cout<<std::fixed<<std::setprecision(10)<<v*v/tan(pi/8)*8<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
