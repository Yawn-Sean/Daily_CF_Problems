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
    i64 n;
    std::cin>>n;
    n=(n%360+360)%360;
    int res=0;
    while(1){
        if(0<=n and n<=45) break;
        if(315<=n and n<360) break;
        res++;
        n=(n+270)%360;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
