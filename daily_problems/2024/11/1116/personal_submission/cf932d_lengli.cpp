/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;
using i128=__int128;

constexpr i64 inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> dep(n+2,0);
    std::vector<i64> w(n+2,0);
    int m=std::__lg(n)+1;
    std::vector<std::vector<int>> fa(n+2,std::vector<int> (m+2,0));
    std::vector<std::vector<i64>> sum(n+2,std::vector<i64> (m+2,inf));

    w[0]=inf,dep[1]=1;

    auto query=[&](int u,i64 c)->int{
        i64 s=0;
        int res=0;
        if(w[u]>c) return res;
        s+=w[u];
        res=1;
        for(int i=m;i>=0;i--){
            if(fa[u][i] and (i128)s+sum[u][i]<=c){
                s+=sum[u][i];
                res+=(1<<i);
                u=fa[u][i];
            }
        }
        return res;
    };
    
    auto insert=[&](int u,int v,i64 c){
        w[u]=c;
        if(w[v]<w[u]){
            for(int i=m;i>=0;i--){
                if(w[fa[v][i]]<w[u]) v=fa[v][i];
            }
            fa[u][0]=fa[v][0];
        }else fa[u][0]=v;

        dep[u]=dep[fa[u][0]]+1;
        sum[u][0]=w[fa[u][0]];

        for(int i=1;i<=m;i++){
            fa[u][i]=fa[fa[u][i-1]][i-1];
            sum[u][i]=sum[u][i-1]+sum[fa[u][i-1]][i-1];
        }
    };

    int count=1,la=0;

    for(int i=1;i<=n;i++){
        i64 op,x,y;
        std::cin>>op>>x>>y;
        i64 u=x^la,c=y^la;
        if(op==1){
            count++;
            insert(count,u,c);
        }else{
            int res=query(u,c);
            la=res;
            std::cout<<res<<"\n";
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
