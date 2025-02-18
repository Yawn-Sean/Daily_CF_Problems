/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<std::array<int,2>>> ans(n+2);
    std::vector<std::vector<int>> eg(n+2); 

    for(int i=1;i<=m;i++){
        int x,y;
        std::cin>>x>>y;
        if(x>y) std::swap(x,y);
        eg[x].pb(y);
    }

    for(int i=1;i<=n;i++){
        ans[i].pb({i,i});
        int sx=i;
        for(auto x:eg[i]){
            sx+=n;
            ans[i].pb({sx,i});
            ans[x].pb({sx,x});
        }
    }

    for(int i=1;i<=n;i++){
        std::cout<<ans[i].size()<<"\n";
        for(auto [x,y]:ans[i]) std::cout<<x<<" "<<y<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
