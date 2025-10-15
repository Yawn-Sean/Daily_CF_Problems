/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=1e18;

void solve(){
    int n,a,b;
    std::string s;
    std::cin>>n>>a>>b>>s;
    std::vector<std::vector<i64>> f(n+2,std::vector<i64> (2,inf));
    f[0][0]=b,f[0][1]=inf;
    for(int i=1;i<=n;i++){
        char c=s[i-1];
        if(c=='1'){
            f[i][1]=std::min(f[i][1],f[i-1][1]+a+b*2);
        }else{
            f[i][0]=std::min(f[i][0],std::min(f[i-1][0]+a+b,f[i-1][1]+2*a+b));
            f[i][1]=std::min(f[i][1],std::min(f[i-1][0]+2*a+2*b,f[i-1][1]+a+b*2));
        }
    }
    std::cout<<f[n][0]<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
