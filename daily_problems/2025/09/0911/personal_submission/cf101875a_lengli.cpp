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
    int n,k;
    std::cin>>n>>k;
    if(std::gcd(n,k)==1){
        std::cout<<1ll*(n-1)*k<<"\n";
        return; 
    }
    int v=std::gcd(n,k);
    int cnt=n/v;
    i64 res=1ll*(cnt-1)*k;
    res*=v;
    res+=1ll*(v-1)*(k-1);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
