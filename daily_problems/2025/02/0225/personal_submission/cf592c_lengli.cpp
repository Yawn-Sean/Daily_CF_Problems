/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define i128 __int128

void solve(){
    i64 t,w,b;
    std::cin>>t>>w>>b;
    i64 res=std::min(w,b)-1;
    i64 d=std::gcd(w,b);

    i128 l=(i128)w*(i128)b/d;
    i128 k=t/l;
    res+=(k-1)*std::min(w,b);
    res+=std::min((i64)(t-l*k+1),std::min(w,b));
    d=std::gcd(res,t);
    std::cout<<res/d<<"/"<<t/d<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
