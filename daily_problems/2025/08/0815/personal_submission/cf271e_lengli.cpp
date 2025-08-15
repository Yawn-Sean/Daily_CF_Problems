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
    i64 n,m;
    std::cin>>n>>m;
    i64 g=0;
    for(int i=0;i<n;i++){
        i64 k;
        std::cin>>k;
        k--;
        while(k%2==0) k/=2;
        g=std::__gcd(g,k);
    }

    i64 res=0;

    auto cal=[&](i64 x){
        while(x<=m){
            res+=m-x;
            x*=2;
        }
    };

    for(int i=1;1ll*i*i<=g;i++){
        if(g%i==0){
            cal(i);
            if(g/i!=i){
                cal(g/i);
            }
        }
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
