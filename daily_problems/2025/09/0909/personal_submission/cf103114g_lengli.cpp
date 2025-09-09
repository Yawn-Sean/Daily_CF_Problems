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
    int n,m;
    std::cin>>n>>m; 

    if(n==1 and m==1){
        std::cout<<1<<"\n";
        return;
    }

    combine cb(n+m+2,1000000007);
    
    Mint res=0;
    auto get=[&](int x,int y){
        return cb.C(x-1,y-1);
    };
    res+=get(m-n,n);
    std::cout<<res*m*cb.aa[n-1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
