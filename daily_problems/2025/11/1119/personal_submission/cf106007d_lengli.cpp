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
    std::vector<std::vector<int>> g(n+2,std::vector<int> (n+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            std::cin>>c;
            g[i][j]=c=='0' ? 0 : 1;
        }
    }

    std::vector<int> st(n+2);
    std::vector<std::array<int,2>> res;

    auto dfs=[&](auto self,int u,int fa)->void{
        st[u]=1;
        for(int i=1;i<=n;i++){
            if(g[u][i] and !st[i]){
                res.pb({u,i});
                self(self,i,u);
            }
        }
    };

    dfs(dfs,1,0);

    if(res.size()==n-1){
        std::cout<<"Yes"<<"\n";
        reverse(all(res));
        for(auto [u,v]:res) std::cout<<u<<" "<<v<<"\n";
    }else{
        std::cout<<"No"<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
