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
    int n;
    std::cin>>n;
    
    std::cout<< -1 <<" "<< 2 <<"\n";
    std::cout<< 0 <<" "<< 2 <<"\n";
    std::cout<< n-1 <<" "<< 1 <<"\n";
    std::cout<< n <<" "<< 0 <<"\n";
    std::cout<< n-1 <<" "<< 0 <<"\n";
    std::cout<< 0 <<" "<< 1 <<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
