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
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    auto check=[&](int d){
        std::vector<std::vector<int>> res(n+2,std::vector<int> (n+2,0));
        for(int i=1;i<=n;i++){
            if(!(a[i]>>d&1)) continue;
            std::queue<int> q;
            std::vector<int> st(n+2);
            q.push(i);
            res[i][i]=1;
            while(q.size()){
                auto u=q.front();
                q.pop();
                if(st[u]) continue;
                st[u]=1;
                for(auto x:eg[u]){
                    if(a[x]>>d&1){
                        res[i][x]=1;
                        q.push(x);
                    }
                }
            }
        }
        return res;
    };

    std::vector<std::vector<int>> res(n+2,std::vector<int> (n+2,0));

    for(int d=0;d<30;d++){
        auto ans=check(d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) res[i][j]|=ans[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            std::cout<<res[i][j];
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
