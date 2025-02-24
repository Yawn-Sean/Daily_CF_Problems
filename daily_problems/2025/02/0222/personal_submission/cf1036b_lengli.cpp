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
    i64 n,m,k;
    std::cin>>n>>m>>k;
    if(n<m) std::swap(n,m);
    if(k<n){
        std::cout<<"-1"<<"\n";
        return;
    }
    if((n-m)%2==1) k--;
    else if((k-n)%2==1) k-=2;
    std::cout<<k<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
