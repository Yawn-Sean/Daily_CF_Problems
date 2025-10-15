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
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=2;i<=n;i++){
        int x;
        std::cin>>x;
        eg[x].pb(i);
    }

    std::vector<int> dist(n+2);
    dist[1]=1;
    int mx=1000000000;

    std::vector<int> res;

    auto dfs=[&](auto self,int u,int fa)->void{
        res.pb(u);
        for(auto x:eg[u]){
            if(x==fa or res.size()==mx) continue;
            dist[x]=dist[u]+1;
            self(self,x,u); 
        }
        if(res.size()!=mx) res.pop_back();
    };

    dfs(dfs,1,0);

    mx=std::min(*max_element(all(dist)),k);

    dfs(dfs,1,0);

    k-=mx;

    std::vector<int> out;

    auto dfs1=[&](auto self,int u,int pre,int ne)->void{
        out.pb(u);
        for(auto x:eg[u]){
            if(x==pre or x==ne or !k) continue;
            k--;
            self(self,x,u,0);
            out.pb(u);
        }
    };

    for(int i=0;i<res.size();i++){
        int pre=(i==0 ? -1 : res[i-1]);
        int ne=(i==res.size()-1 ? -1 : res[i+1]);
        dfs1(dfs1,res[i],pre,ne);
    }

    std::cout<<out.size()-1<<"\n";
    for(auto x:out) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
