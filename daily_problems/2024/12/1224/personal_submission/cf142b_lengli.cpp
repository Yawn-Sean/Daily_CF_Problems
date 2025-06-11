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
    if(n==1){
        std::cout<<m<<"\n";
        return;
    }
    if(m==1){
        std::cout<<n<<"\n";
        return;
    }
    if((n==2 and m==3) or (n==3 and m==2) or (n==2 and m==2)){
        std::cout<<4<<"\n";
        return;
    }
    if(n>m) std::swap(n,m);
    i64 res=(1ll*n*m)/2+(1ll*n*m)%2;
    
    if(n==2){
        res=std::max(res,(1ll*m/4)*4+std::min(1ll*m%4,2ll)*2);
        std::cout<<res<<"\n";
    }else std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
