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
    std::vector<int> rd(n+2);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        rd[u]++;
        rd[v]++;
    }
    i64 res=1ll*(n-2)*(n-1)*n/6;
    i64 ans=0;
    for(int i=1;i<=n;i++){
        ans+=1ll*rd[i]*(n-1-rd[i]);
    }
    std::cout<<res-ans/2<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
