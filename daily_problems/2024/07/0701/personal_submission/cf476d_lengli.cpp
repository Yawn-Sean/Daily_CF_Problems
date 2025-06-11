/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<int>> res(n);
    int ma=0;
    for(int i=0,j=1;i<n;i++,j+=6){
        res[i].pb(j*k);
        res[i].pb((j+1)*k);
        res[i].pb((j+2)*k);
        res[i].pb((j+4)*k);
        for(auto x:res[i]) ma=std::max(x,ma);
    }
    std::cout<<ma<<"\n";
    for(auto x:res){
        for(auto y:x) std::cout<<y<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
