/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

void solve(){
    int a,b,c;
    std::cin>>a>>b>>c;
    for(int i=0;i<=std::min(a,c);i++){
        int v=(c-(1ll*i*inf)%c)%c;
        if(v>=0 and v<=b) continue;
        std::cout<<1<<" "<<std::setw(9)<<std::setfill('0')<<i<<"\n";
        return;
    }
    std::cout<<2<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
