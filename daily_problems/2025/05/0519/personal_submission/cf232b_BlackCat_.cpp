#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
static constexpr i64 mod=1e9+7;
i64 f[105],inv[105];
i64 qpow(i64 a,i64 b){
    i64 ans=1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    return ans;
}
i64 c(i64 a,i64 b){
    return f[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve(){
    i64 n,m,k;
    std::cin>>n>>m>>k;
    std::vector dp(k+1,0ll);
    dp[0]=1;
    i64 ww=(m/n)%(mod-1);
    i64 need=(m%n);
    for(int i=1;i<=n;i++){
        std::vector ndp(k+1,0ll);
        for(int j=0;j<=n;j++){
            i64 vvv=qpow(c(n,j),(ww+(i<=need)));
            for(int l=0;l<=k;l++){
                if(l+j>k){
                    break;
                }
                ndp[l+j]+=(dp[l]*vvv)%mod;
                ndp[l+j]%=mod;
            }
        }
        dp=std::move(ndp);
    }
    std::cout<<dp[k]<<endl;

}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=100;i++){
        f[i]=f[i-1]*i%mod;
    }
    inv[0]=1;
    inv[100]=qpow(f[100],mod-2);
    for(int i=99;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    while(t--){
        solve();
    }
    return 0;
}
