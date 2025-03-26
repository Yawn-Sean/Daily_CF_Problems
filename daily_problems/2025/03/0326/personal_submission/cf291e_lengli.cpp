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
    ACAM acam(300010,26);
    std::vector<std::vector<std::pair<int,std::string>>> eg(n+2);
    for(int i=2;i<=n;i++){
        int p;
        std::string s;
        std::cin>>p>>s;
        eg[p].pb(std::make_pair(i,s));
        eg[i].pb(std::make_pair(p,s));
    }

    auto dfs=[&](auto self,int u,int fa,int pos)->void{
        for(auto [v,s]:eg[u]){
            if(v==fa) continue;
            int id=acam.insert(s,pos,1);
            self(self,v,u,id);
        }
    };

    dfs(dfs,1,0,0);

    std::string str;
    std::cin>>str;
    auto ans=acam.insert(str,0,0);

    acam.get_fail();
    acam.build_tree();
    acam.dfs(0,-1);

    std::cout<<acam.sum[ans]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
