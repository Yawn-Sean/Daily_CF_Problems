/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#pragma GCC optimize("O3,Ofast,unroll-loops")

std::vector<int> sieve(int len){
    std::vector<int> prime,st(len+2),val(len+2);
    for(int i=2;i<=len;i++){
        if(!st[i]) prime.pb(i),val[i]=i;
        for(int j=0;prime[j]*i<=len;j++){
            st[prime[j]*i]=1;
            val[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return val;
}

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> p(n+2);
    std::vector<std::array<int,2>> edge;
    auto min_prime=sieve(10000010);
    std::vector<int> cnt(10000010);
    auto split=[&](int x){
        while(x>1){
            int v=min_prime[x];
            while(x%v==0) x/=v;
            cnt[v]++;
        }
    };
    for(int i=1;i<=n;i++){
        std::cin>>p[i];
        split(p[i]);
    }
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        edge.pb({u,v});
    }

    std::vector<std::vector<int>> eg(n+2);

    auto check=[&](int x)->bool{
        for(int i=1;i<=n;i++) eg[i].clear();
        for(auto [u,v]:edge) {
            if(p[u]%x==0 and p[v]%x==0){
                eg[u].pb(v);
                eg[v].pb(u);
            }
        }
        std::vector<int> vis(n+2,0);
        int mx=0; 
        auto dfs=[&](auto self,int u,int fa)->int{
            vis[u]=1;
            int best1=0,best2=0; 
            for(int v:eg[u]) {
                if(v==fa) continue;
                int d=self(self,v,u)+1; 
                if(d>best1){
                    best2=best1; 
                    best1=d;
                }else if(d>best2){
                    best2=d;
                }
            }
            mx=std::max(mx,best1+best2);
            return best1;
        };
 
        for(int i=1;i<=n;i++) {
            if(!vis[i] and !eg[i].empty()) {
                dfs(dfs,i,0);
            }
        }
 
        return (mx+1)*2>n;
    };

    for(int i=1;i<=10000000;i++){
        if(cnt[i]*2>n){
            if(check(i)){
                std::cout<<"YES"<<"\n";
                return;
            }
        }
    }
    std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
