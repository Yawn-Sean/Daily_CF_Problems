/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr long long inf=2e18;

#define int long long

void solve(){
    int n,m,b;
    std::cin>>n>>m>>b;
    std::vector<int> f(1<<m,inf);

    std::vector<std::array<int,3>> pp(n+2);
    std::vector<int> pb(n+2);
    for(int i=1;i<=n;i++){
        int c,k,t;
        std::cin>>c>>k>>t;
        pp[i]={k,c,i};
        int ans=0;
        for(int j=0;j<t;j++){
            int x;
            std::cin>>x;
            x--;
            ans+=(1<<x);
        }
        pb[i]=ans;
    }
    sort(pp.begin()+1,pp.begin()+1+n);
    f[0]=0;
    int res=inf;
    for(int i=1;i<=n;i++){
        std::vector<int> g=f;
        auto [k,c,id]=pp[i];
        int v=pb[id];
        for(int j=0;j<(1<<m);j++){
            if(f[j]==inf) continue;
            g[j|v]=std::min(g[j|v],f[j]+c);
        }
        f.swap(g);
        int ans=f[(1<<m)-1];
        if(ans!=inf) res=std::min(res,ans+k*b);
    }

    if(res==inf) res=-1;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
