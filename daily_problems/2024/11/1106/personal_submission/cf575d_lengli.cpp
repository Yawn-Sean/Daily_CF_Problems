/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::cout<<2000<<"\n";
    for(int i=1;i<=1000;i++){
        std::cout<<i<<" "<<1<<" "<<i<<" "<<2<<"\n"; 
    }
    for(int i=1000;i>=1;i--){
        std::cout<<i<<" "<<1<<" "<<i<<" "<<2<<"\n"; 
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
