/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

//u,r,d,l
int dx[5]={-1,0,1,0,0};
int dy[5]={0,1,0,-1,0};

#define int long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<int> rd(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
        rd[u]++,rd[v]++;
        if(rd[u]>4 or rd[v]>4){
            std::cout<<"NO"<<"\n";
            return;
        }
    }
    std::vector<int> xx(n+2),yy(n+2);

    auto dfs=[&](auto self,int u,int fa,int fx,int len,int x,int y)->void{
        xx[u]=x,yy[u]=y;
        std::vector<int> d;
        for(int i=0;i<4;i++){
            if(i==(fx^2)) continue;
            d.pb(i);
        }
        for(auto v:eg[u]){
            if(v==fa) continue;
            int t=d.back();
            self(self,v,u,t,len/2,x+len*dx[t],y+len*dy[t]);
            d.pop_back();
        }
    };

    dfs(dfs,1,-1,4,1e17,0,0);

    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++) std::cout<<xx[i]<<" "<<yy[i]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
