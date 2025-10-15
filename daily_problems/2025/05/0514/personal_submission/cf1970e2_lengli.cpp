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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> s(n),l(n);
    for(auto &x:s) std::cin>>x;
    for(auto &x:l) std::cin>>x;
    matrix<Mint> a(n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]+=(Mint)s[i]*s[j]+(Mint)s[i]*l[j]+(Mint)s[j]*l[i];
        }
    }
    matrix<Mint> f(n,1);
    f[0][0]=1;
    a^=m;
    auto res=a*f;

    Mint ans=0;
    for(int i=0;i<n;i++) ans+=res[i][0];
    std::cout<<ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
