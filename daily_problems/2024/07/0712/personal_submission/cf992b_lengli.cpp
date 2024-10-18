/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int l,r,x,y;
    std::cin>>l>>r>>x>>y;
    int res=0;
    for(int i=1;1ll*i*i<=y;i++){
        if(y%i) continue;
        int a=i,b=1ll*x*y/a;
        int d=std::gcd(a,b);
        if(a>=l and a<=r and b>=l and b<=r and d==x and 1ll*a*b/d==y) res++;
        if(1ll*i*i!=y){
            a=y/i,b=1ll*x*y/a;
            d=std::gcd(a,b);
            if(a>=l and a<=r and b>=l and b<=r and d==x and 1ll*a*b/d==y) res++;
        }
        
    }
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
