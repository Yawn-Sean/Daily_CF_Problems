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
    int a,b;
    std::cin>>a>>b;
    std::vector<std::array<int,2>> pa(a),pb(b);
    for(auto &[x,y]:pa) std::cin>>x>>y;
    for(auto &[x,y]:pb) std::cin>>x>>y;
    if(a==b) std::cout<<"Yes"<<"\n";
    else std::cout<<"No"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
