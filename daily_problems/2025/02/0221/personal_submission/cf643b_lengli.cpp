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
    int a,b,c,d;
    std::cin>>a>>b>>c>>d;
    if(n>=k or n<=4){
        std::cout<<"-1"<<"\n";
        return;
    }
    std::vector<std::array<int,2>> res;
    std::vector<int> q;
    for(int i=1;i<=n;i++){
        if(i==a or i==b or i==c or i==d) continue;
        q.pb(i);
    }
    std::cout<<a<<" "<<c<<" ";
    for(auto x:q) std::cout<<x<<" ";
    std::cout<<d<<" "<<b<<"\n";

    std::cout<<c<<" "<<a<<" ";
    for(auto x:q) std::cout<<x<<" ";
    std::cout<<b<<" "<<d<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
