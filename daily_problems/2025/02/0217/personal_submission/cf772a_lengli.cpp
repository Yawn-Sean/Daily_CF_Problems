/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define f64 long double

void solve(){
    int n,p;
    std::cin>>n>>p;
    std::vector<std::array<int,2>> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i][0]>>a[i][1];

    auto check=[&](f64 x){
        f64 res=0;
        for(int i=1;i<=n;i++){
            auto [l,r]=a[i];
            if((f64)l*x>(f64)r) res+=(f64)l*x-(f64)r;
        }
        return (f64)x*p>=res;
    };

    f64 l=0,r=(f64)100000000000;

    if(check(r)){
        std::cout<<"-1"<<"\n";
        return;
    }

    for(int i=0;i<200;i++){
        f64 mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    std::cout<<std::fixed<<std::setprecision(10)<<l<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
