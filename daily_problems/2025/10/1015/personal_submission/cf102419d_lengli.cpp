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

    std::vector<int> hv;

    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        if(a[u]==a[v]){
            eg[u].pb(v);
            eg[v].pb(u);
        }else{
            hv.pb(a[u]^a[v]);
        }
    }

    std::sort(all(hv));
    
    std::vector<int> col(n+2,-1);
    std::vector<int> res;

    bool flag=1;

    auto dfs=[&](auto self,int u,int fa,int c)->void{
        col[u]=c;
        if(c) res.pb(u);
        for(auto x:eg[u]){
            if(x==fa) continue;
            if(col[x]!=-1){
                if(col[x]==c) flag=0;
                continue;
            }
            self(self,x,u,c^1);
        }
    };

    for(int i=1;i<=n and flag;i++){
        if(col[i]==-1){
            dfs(dfs,i,0,1);
        }
    }

    if(!flag){
        std::cout<<"-1"<<"\n";
        return;
    }

    int x=1;
    for(auto t:hv){
        if(x==t) x++;
    }

    std::cout<<res.size()<<" "<<x<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
