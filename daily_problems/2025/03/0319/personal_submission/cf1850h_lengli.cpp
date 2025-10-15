/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=3e14;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    for(int i=1;i<=m;i++){
        int a,b,d;
        std::cin>>a>>b>>d;
        eg[a].pb({b,d});
        eg[b].pb({a,-d});
    } 

    std::vector<i64> d(n+2,-1);

    bool flag=1;

    auto dfs=[&](auto self,int x,i64 len){
        if(d[x]!=-1){
            if(d[x]==len) return;
            flag=0;
            return;
        }
        d[x]=len;
        for(auto [v,w]:eg[x]){
            self(self,v,len+w);
        }
    };

    for(int i=1;i<=n and flag;i++){
        if(d[i]==-1){
            dfs(dfs,i,inf);
        }
    }
    std::cout<<(flag ? "YES" : "NO")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
