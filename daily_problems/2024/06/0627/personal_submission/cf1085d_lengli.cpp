/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,s;
    std::cin>>n>>s;
    std::vector<int> d(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        d[u]++,d[v]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(d[i]==1) cnt++;
    std::cout<<std::fixed<<std::setprecision(10)<<(double)s*2.0/cnt;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
