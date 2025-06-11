/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    std::vector<std::array<int,3>> edge;
    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        edge.pb({u,v,w});
        eg[u].pb({v,w});
        eg[v].pb({u,w});
    }

    std::vector<int> st(n+2),sig(n+2),val(n+2);
    std::vector<double> ans(n+2);

    std::vector<double> q;

    auto dfs1=[&](auto self,int u,int fa,int &root)->void{
        int nsig=sig[u]==1 ? -1 : 1;
        q.pb(-sig[u]*val[u]);
        for(auto [v,c]:eg[u]){
            if(v==fa) continue;
            int nw=c-val[u];
            if(sig[v]!=0){
                if(sig[v]!=nsig){
                    if(sig[v]==1){
                        double tmp=nw-val[v];
                        tmp/=2.0;
                        ans[v]=sig[v]*tmp+val[v];
                    }else{
                        double tmp=val[v]-nw;
                        tmp/=2.0;
                        ans[v]=sig[v]*tmp+val[v];
                    }
                    root=v;
                }
            }else{
                sig[v]=nsig;
                val[v]=nw;
                self(self,v,u,root);
            }
        }
    };

    auto dfs2=[&](auto self,int u,int fa)->void{
        st[u]=1;
        for(auto [v,c]:eg[u]){
            if(v==fa or st[v]) continue;
            ans[v]=1.0*c-ans[u];
            self(self,v,u);
        }
    };

    auto check=[&](int u){
        sig[u]=1,val[u]=0;
        q.clear();
        q.pb(0);
        int root=-1;
        dfs1(dfs1,u,0,root);
        if(root==-1){
            root=u;
            int k=q.size();
            sort(all(q));
            ans[root]=q[k/2];
        }
        dfs2(dfs2,root,0);
    };

    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        check(i);
    }

    bool flag=1;
    for(auto [u,v,w]:edge){
        if(ans[u]+ans[v]!=1.0*w) flag=0;
    }

    if(!flag) std::cout<<"NO"<<"\n";
    else{
        std::cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++){
            std::cout<<std::fixed<<std::setprecision(10)<<ans[i]<<" ";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
