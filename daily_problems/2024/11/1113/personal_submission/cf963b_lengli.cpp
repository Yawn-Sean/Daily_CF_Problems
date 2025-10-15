/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<int> rd(n+2);
    for(int i=1;i<=n;i++){
        int p;
        std::cin>>p;
        if(p==0) continue;
        eg[p].pb(i);
        eg[i].pb(p);
        rd[i]++,rd[p]++;
    }

    int root=1;
    for(int i=1;i<=n;i++){
        if(eg[i].size()&1) continue;
        root=i;
        break;
    }

    std::vector<int> res,st(n+2,0);
    auto dfs1=[&](auto self,int u,int fa)->void{
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
        if(rd[u]%2==0){
            st[u]=1;
            res.pb(u);
            for(auto x:eg[u]) rd[x]--;
        }
    };

    dfs1(dfs1,root,0);

    bool flag=1;

    auto dfs2=[&](auto self,int u,int fa)->void{
        if(!flag) return;
        if(rd[u]>=0 and !st[u]){
            if(rd[u]&1) flag=0;
            else{
                st[u]=1;
                res.pb(u);
                for(auto x:eg[u]) rd[x]--;
            }
        }
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
    };

    dfs2(dfs2,root,0);

    std::cout<<(flag ? "YES" : "NO")<<"\n";
    if(flag) for(auto x:res) std::cout<<x<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
