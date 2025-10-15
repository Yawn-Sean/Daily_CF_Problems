/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> &grid){
    int n=grid.size(),m=grid[0].size();
    std::vector<std::vector<int>> res(m,std::vector<int> (n));
    for(int i=0,jj=n-1;i<n;i++,jj--){
        for(int j=0,ii=0;j<m;j++,ii++){
            res[ii][jj]=grid[i][j];
        }
    }
    return res;
};


void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> g(n+2,std::vector<int> (m+2,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            std::cin>>g[i][j];
        }
    }

    std::vector<std::pair<std::string,int>> res;

    auto getr=[&](){
        for(int i=1;i<=n;i++){
            int mi=inf;
            for(int j=1;j<=m;j++){
                mi=std::min(mi,g[i][j]);
            }
            if(mi==0) continue;
            for(int j=1;j<=m;j++) g[i][j]-=mi;
            for(int j=1;j<=mi;j++) res.pb(std::make_pair("row",i));
        }
    };

    auto getc=[&](){
        for(int j=1;j<=m;j++){
            int mi=inf;
            for(int i=1;i<=n;i++){
                mi=std::min(mi,g[i][j]);
            }
            if(mi==0) continue;
            for(int i=1;i<=n;i++) g[i][j]-=mi;
            for(int i=1;i<=mi;i++) res.pb(std::make_pair("col",j));
        }
    };

    if(n>m) getc(),getr();
    else getr(),getc();
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]){
                std::cout<<"-1"<<"\n";
                return;
            }
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto [a,b]:res) std::cout<<a<<" "<<b<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
