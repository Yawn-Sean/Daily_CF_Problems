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
    if(n==1 and m==1){
        std::cout<<1<<"\n";
    }else if(n==1 or m==1){
        std::cout<<2<<"\n";
    }else if(n==m){
        std::cout<<8<<"\n";
    }else std::cout<<4<<"\n";

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
