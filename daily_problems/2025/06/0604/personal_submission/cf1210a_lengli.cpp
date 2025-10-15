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
    std::vector<std::bitset<8>> g(8);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        g[u][v]=g[v][u]=1;
    }
    if(n<=6) std::cout<<m<<"\n";
    else{
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int cnt=0;
                for(int k=1;k<=n;k++){
                    if(g[i][k] and g[j][k]){
                        cnt++;
                    }
                }
                res=std::max(res,m-cnt);
            }
        }
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
