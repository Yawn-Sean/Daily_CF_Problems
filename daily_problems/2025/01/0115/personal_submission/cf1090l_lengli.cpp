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
    i64 t,n,a,b,k;
    std::cin>>t>>n>>a>>b>>k;
    i64 x=(n+1)/2,y=n/2;
    i64 res=0;
    i64 l=0,r=t;

    auto check=[&](i64 c){
        return std::min(c,a)*x+std::min(c,b)*y>=1ll*c*k;
    };

    while(l<r){
        i64 mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    std::cout<<l<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
