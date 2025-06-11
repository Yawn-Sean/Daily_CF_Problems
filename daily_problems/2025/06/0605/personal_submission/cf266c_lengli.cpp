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
    std::vector<std::vector<int>> g(n+2,std::vector<int> (n+2,0));
    for(int i=1;i<n;i++){
        int x,y;
        std::cin>>x>>y;
        g[x][y]=1;
    }

    std::vector<std::array<int,3>> res;

    auto dfs=[&](auto self,int dep){
        if(dep==1) return;
        for(int j=1;j<dep;j++){
            bool flag=0;
            for(int i=1;i<=dep;i++){
                flag|=g[i][j];
            }
            if(!flag){
                for(int i=1;i<=n;i++){
                    std::swap(g[i][j],g[i][dep]);
                }
                res.pb({2,j,dep});
                break;
            }
        }
        for(int i=1;i<dep;i++){
            bool flag=0;
            for(int j=1;j<=dep;j++){
                flag|=g[i][j];
            }
            if(flag){
                for(int j=1;j<=n;j++){
                    std::swap(g[i][j],g[dep][j]);
                }
                res.pb({1,i,dep});
                break;
            }
        }
        self(self,dep-1);
    };

    dfs(dfs,n);

    std::cout<<res.size()<<"\n";
    for(auto [a,b,c]:res) std::cout<<a<<" "<<b<<" "<<c<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
