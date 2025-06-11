/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> q(n);
    for(auto &[c,v]:q){
        std::cin>>c>>v;
    }
    sort(all(q),[&](auto l,auto r){
        return (100-r[1])*l[0]*l[1]>(100-l[1])*r[0]*r[1];
    });

    long long res=0,sum=0;
    for(auto [c,v]:q){
        res+=c*10000;
        res+=(100-v)*sum;
        sum+=c*v;
    }
    std::cout<<std::fixed<<std::setprecision(9)<<res/10000.0<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
