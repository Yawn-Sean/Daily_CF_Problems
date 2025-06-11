/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,k,p;
    std::cin>>n>>k>>p;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        a[i]=(a[i-1]+a[i])%p;
    }
    std::vector<std::vector<int>> f(p,std::vector<int> (k+2,-2e9));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int l=k;l>=1;l--){
            for(int j=0;j<p;j++){
                f[a[i]][l]=std::max(f[a[i]][l],f[j][l-1]+((a[i]-j)%p+p)%p);
            }
        }
    }
    std::cout<<f[a[n]][k];
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
