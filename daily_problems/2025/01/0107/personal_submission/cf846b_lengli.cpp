/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9+10;

void solve(){
    int n,m,s;
    std::cin>>n>>m>>s;
    std::vector<int> a(m);

    std::vector<int> g(m+2);
    for(int i=0;i<m;i++) std::cin>>a[i];
    sort(all(a));

    g[0]=0;
    for(int i=1;i<=m;i++){
        g[i]=a[i-1]+g[i-1];
    }
    g[m+1]=g[m];

    std::vector<std::vector<int>> f(n+2,std::vector<int> (n*m+n+2,inf));
    f[0][0]=0;

    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n*m+n;j++){
            for(int d=0;d<=m+1;d++){
                if(j-d>=0) f[i][j]=std::min(f[i][j],f[i-1][j-d]+g[d]);
                if(f[i][j]<=s) res=std::max(res,j);
            }
        }   
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
