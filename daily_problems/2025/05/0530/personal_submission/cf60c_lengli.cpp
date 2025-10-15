/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

void solve(){
    int n,m;
    std::cin>>n>>m;

    std::vector<std::vector<std::array<int,3>>> eg(n+2);

    for(int i=1;i<=m;i++){
        int u,v,g,l;
        std::cin>>u>>v>>g>>l;
        eg[u].pb({v,g,l});
        eg[v].pb({u,g,l});

    }

    std::vector<i64> a(n+2);

    auto dfs=[&](auto self,int u,int fa)->bool{
        for(auto [v,g,l]:eg[u]){
            if(v==fa) continue;
            if(a[v]){
                if(std::__gcd(a[u],a[v])!=g) return 0;
                if(1ll*a[u]*a[v]!=1ll*l*g) return 0;
                continue;
            }
            a[v]=1ll*l*g/a[u];
            if(a[v]<=0 or a[v]>1000000) return 0;
            if(std::__gcd(a[v],a[u])!=g) return 0;
            if(1ll*a[u]*a[v]!=1ll*l*g) return 0;
            if(!self(self,v,u)) return 0;
        }
        return 1;
    };

    auto remove=[&](auto self,int u,int fa)->void{
        a[u]=0;
        for(auto [v,g,l]:eg[u]){
            if(v==fa) continue;
            if(a[v]) self(self,v,u);
        }
    };  

    for(int i=1;i<=n;i++){
        if(a[i]) continue;
        for(int j=1;j<=1000000;j++){
            a[i]=j;
            if(!dfs(dfs,i,0)) remove(remove,i,0);
            else break;
        }
        if(!a[i]){
            std::cout<<"NO"<<"\n";
            return;
        }
    }

    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
