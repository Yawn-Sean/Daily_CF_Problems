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
    i64 n,k;
    int p;
    std::cin>>n>>k>>p;
    
    auto query=[&](i64 n,i64 k,i64 x){
        if(x&1){
            if(k<=n/2) return '.';
            return (n-(x+1)/2+1<=k ? 'X' : '.');
        }
        return ((n-x)/2+1<=k ? 'X' : '.');

    };

    while(p--){
        i64 x;
        std::cin>>x;
        if(n&1){
            if(x==n){
                std::cout<<(k ? 'X' : '.');
            }else{
                std::cout<<query(n-1,k-1,x);
            }
        }else std::cout<<query(n,k,x);
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
