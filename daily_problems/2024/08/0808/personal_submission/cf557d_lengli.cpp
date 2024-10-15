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
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<=m;i++){
        int a,b;
        std::cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }
    if(!m){
        std::cout<<3<<" "<<1ll*(n-2)*(n-1)*n/6<<"\n";
        return;
    }

    std::vector<int> col(n+2,-1);

    auto dfs=[&](auto self,int u,int c,std::array<int,2> &cnt)->bool{
        if(col[u]!=-1) return col[u]==c;
        col[u]=c;cnt[c]++;
        bool flag=1;
        for(auto x:eg[u]){
            flag&=self(self,x,c^1,cnt); 
        }
        return flag;
    };

    long long res=0;
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            std::array<int,2> cnt={0,0};
            auto flag=dfs(dfs,i,0,cnt);
            if(!flag) {
                std::cout<<0<<" "<<1<<"\n"; 
                return;
            }
            if(cnt[0]>=2) res+=1ll*cnt[0]*(cnt[0]-1)/2;
            if(cnt[1]>=2) res+=1ll*cnt[1]*(cnt[1]-1)/2;
        }
    }
    if(res) std::cout<<1<<" "<<res<<"\n";
    else std::cout<<2<<" "<<1ll*(n-2)*m<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
