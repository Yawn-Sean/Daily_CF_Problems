/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long
#define double long double

void solve(){
    int x,y;
    std::cin>>x>>y;
    if(y>x){
        std::cout<<"-1"<<"\n";
        return;
    }
    if(x==y){
        std::cout<<x<<"\n";
        return;
    }
    auto f=[&](double d)->double{
        int v=d/(2.0*y);
        double ans=d/(2.0*v);
        return ans;
    };
    std::cout<<std::fixed<<std::setprecision(10)<<std::min(f(x-y),f(x+y))<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
