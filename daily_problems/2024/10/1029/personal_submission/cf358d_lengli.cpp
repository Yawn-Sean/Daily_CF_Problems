/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),b(n+2),c(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) std::cin>>b[i];
    for(int i=1;i<=n;i++) std::cin>>c[i];

    std::vector<std::vector<int>> f(n+2,std::vector<int> (2,0));

    f[0][1]=-1e9;

    for(int i=1;i<=n;i++){
        f[i][0]=std::max(f[i][0],f[i-1][0]+b[i]);
        f[i][0]=std::max(f[i][0],f[i-1][1]+c[i]);
        f[i][1]=std::max(f[i][1],f[i-1][0]+a[i]);
        f[i][1]=std::max(f[i][1],f[i-1][1]+b[i]);
    }

    std::cout<<f[n][1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
