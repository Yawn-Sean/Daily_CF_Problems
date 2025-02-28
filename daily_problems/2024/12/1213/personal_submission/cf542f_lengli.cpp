/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,T;
    std::cin>>n>>T;
    std::vector<std::vector<int>> a(T+2),b(T+2); 
    for(int i=1;i<=n;i++){
        int t,q;
        std::cin>>t>>q;
        a[T-t].pb(q);
    }
    for(int i=0;i<=T;i++){
        sort(all(a[i]),std::greater<>());
        b[i].pb(0);
        for(int j=0;j<a[i].size();j++){
            b[i].pb(b[i][j]+a[i][j]);
        }
    }
    std::vector<std::vector<int>> f(T+2,std::vector<int> (n+2,0));
    for(int i=T+1;i>=1;i--){
        for(int j=0;j<=n;j++){
            for(int k=0;k<b[i-1].size();k++){
                f[i-1][(j+1)/2+k]=std::max(f[i-1][(j+1)/2+k],f[i][j]+b[i-1][k]);
            }
        }
    }
    std::cout<<f[0][1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
