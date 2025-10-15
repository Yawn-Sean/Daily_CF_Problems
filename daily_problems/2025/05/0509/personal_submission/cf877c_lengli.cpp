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
    std::vector<int> res;
    for(int i=2;i<=n;i+=2) res.pb(i);
    for(int i=1;i<=n;i+=2) res.pb(i);
    for(int i=2;i<=n;i+=2) res.pb(i);
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
