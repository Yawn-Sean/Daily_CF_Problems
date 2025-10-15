/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;


void solve(){
    int n;
    std::cin>>n;
    int m=n*2;
    std::vector<int> a(m+2);   
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        a[i+n]=a[i];
    }

    std::vector<std::vector<int>> g(20,std::vector<int> (m+2,inf));
    std::vector<std::vector<int>> f(20,std::vector<int> (m+2,inf));
    std::vector<int> b(m+2);
    for(int i=1;i<=m;i++){
        b[i]=std::max(1,i-a[i]);
        g[0][i]=i;
    }

    for(int i=1;i<20;i++)
        for(int j=1;j+(1<<i)-1<=n*2;j++)
            g[i][j]=b[g[i-1][j]]<=b[g[i-1][j+(1<<i-1)]] ? g[i-1][j] : g[i-1][j+(1<<i-1)];

    auto query=[&](int l,int r){
        int k=log(r-l+1)/log(2);
        return b[g[k][l]]<=b[g[k][r-(1<<k)+1]] ? g[k][l] : g[k][r-(1<<k)+1];
    };


    for(int i=0;i<20;i++){
        for(int j=1;j<=m;j++){
            if(i==0) f[i][j]=query(b[j],j);
            else f[i][j]=f[i-1][f[i-1][j]];
        }
    }

    i64 res=0;
    for(int i=1;i<=n;i++){
        int idx=i+n-1;
        if(b[idx]<=i){
            res++;
            continue;
        }
        for(int t=19;t>=0;t--){
            if(f[t][idx]!=inf and b[f[t][idx]]>i){
                res+=(1<<t);
                idx=f[t][idx];
            }
        }
        res+=2;
    }
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
