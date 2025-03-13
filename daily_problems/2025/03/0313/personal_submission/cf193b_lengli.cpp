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

constexpr i64 inf=1e18;

void solve(){
    int n,m,r;
    std::cin>>n>>m>>r;

    std::vector<int> a(n+2),b(n+2),k(n+2),p(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) std::cin>>b[i];
    for(int i=1;i<=n;i++) std::cin>>k[i];
    for(int i=1;i<=n;i++) std::cin>>p[i];

    i64 res=-inf;

    auto dfs=[&](auto self,int pos,std::vector<int> v,int flag)->void{
        if(pos==m+1){
            i64 ans=0;
            for(int i=1;i<=n;i++) ans+=1ll*v[i]*k[i];
            res=std::max(ans,res);
            return;
        }
        std::vector<int> tmp(n+2);
        if(!((m-pos+1)&1)) self(self,m+1,v,1);
        
        if(flag){
            for(int i=1;i<=n;i++) tmp[i]=v[i]^b[i];
            self(self,pos+1,tmp,0);
        }
        for(int i=1;i<=n;i++) tmp[i]=v[p[i]]+r;
        self(self,pos+1,tmp,1);

    };

    dfs(dfs,1,a,1);

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
