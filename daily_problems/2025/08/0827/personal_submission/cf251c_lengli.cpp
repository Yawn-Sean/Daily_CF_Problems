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
    i64 a,b,k;
    std::cin>>a>>b>>k;

    int c=360360;

    std::vector<i64> f(10000010);

    auto dp=[&](auto self,i64 x,i64 y)->i64{
        f[0]=0;
        for(int i=1;i<=x-y;i++){
            f[i]=f[i-1]+1;
            for(int j=2;j<=k;j++){
                if((y+i)%j<=i){
                    f[i]=std::min(f[i],f[i-(y+i)%j]+1);
                }
            }
        }
        return f[x-y];
    };

    if(a/c==b/c){
        std::cout<<dp(dp,a,b)<<"\n";
    }else{
        std::cout<<dp(dp,a%c,0)+dp(dp,c,b%c)+dp(dp,c,0)*(a/c-(b+c-1)/c)<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
