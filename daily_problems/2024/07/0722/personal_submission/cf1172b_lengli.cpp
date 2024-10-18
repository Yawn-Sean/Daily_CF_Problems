/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    Mint res=1;
    std::vector<int> cnt(n+2,0);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        cnt[u]++,cnt[v]++;
        res*=cnt[u];
        res*=cnt[v];
    }
    std::cout<<res*n;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
