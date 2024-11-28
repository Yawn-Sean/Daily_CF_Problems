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
    std::vector<std::vector<double>> f(n+2,std::vector<double> (n+2,0));
    f[0][0]=0;

    for(int i=1;i<=n;i++) {
        f[i][0]=f[i-1][0]+(double)n/i;
        f[0][i]=f[0][i-1]+(double)n/i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            double ans=(double)i*(n-j)*f[i-1][j];
            ans+=(double)(n-i)*j*f[i][j-1];
            ans+=(double)i*j*f[i-1][j-1];
            ans+=n*n;
            ans/=(double)(n*n)-(double)(n-j)*(n-i);
            f[i][j]=ans;
        }
    }

    std::vector<int> h(n+2,0),l(n+2,0);
    for(int i=1;i<=m;i++){
        int x,y;
        std::cin>>x>>y;
        h[x]=1,l[y]=1;
    }
    int cnth=n,cntl=n;
    for(int i=1;i<=n;i++){
        cnth-=h[i];
        cntl-=l[i];
    }

    std::cout<<std::fixed<<std::setprecision(10)<<f[cnth][cntl]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
