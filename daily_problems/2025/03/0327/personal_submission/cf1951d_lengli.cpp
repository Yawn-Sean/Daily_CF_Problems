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
    std::cin>>n>>k;
    if(n==k){
        std::cout<<"YES"<<"\n";
        std::cout<<1<<"\n"<<1<<"\n";
    }else if((n-k+1)*2<=n){
        std::cout<<"NO"<<"\n";
    }else{
        std::cout<<"YES"<<"\n";
        std::cout<<2<<"\n";
        std::cout<<(n-k+1)<<" "<<1<<"\n"; 
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
