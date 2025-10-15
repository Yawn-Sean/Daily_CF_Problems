/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=2e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> a(n);
    for(auto &[x,c]:a) std::cin>>x>>c;
    std::sort(all(a));
    std::vector<std::vector<i64>> f(n+2,std::vector<i64> (n+2,inf));
    f[1][1]=a[0][1];
    for(int i=2;i<=n;i++){
        auto [x,v]=a[i-1];
        i64 mi=inf;
        for(int j=1;j<i;j++) mi=std::min(mi,f[i-1][j]);
        for(int j=1;j<=i;j++){
            if(i==j){
                f[i][j]=std::min(f[i][j],mi+v);
            }else{
                f[i][j]=std::min(f[i][j],f[i-1][j]+std::abs(x-a[j-1][0]));
            }
        }
    }

    i64 res=inf;
    for(int j=1;j<=n;j++) res=std::min(res,f[n][j]);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
