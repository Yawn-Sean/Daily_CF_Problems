#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
static constexpr i64 mod=1e9+7;
void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<i64> a(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        a[i]/=2;
        a[i]--;
    }
    k--;
    i64 dp[n+10][2][(1<<13)];
    memset(dp,0ll,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            for(int j=0;j<(1<<12);j++){
                if(j+1>=(1<<k)){
                    dp[i][1][0]+=dp[i-1][0][j];
                    dp[i][1][0]%=mod;
                }
                else{
                    dp[i][0][j+1]+=dp[i-1][0][j];
                    dp[i][0][j+1]%=mod;
                }
                
            }
            dp[i][1][0]+=dp[i-1][1][0];
                dp[i][1][0]%=mod;
        }
        else if(a[i]==1){
            for(int j=0;j<(1<<12);j++){
                if(j&1){
                    if(2>=(1<<k)){
                        dp[i][1][0]+=dp[i-1][0][j];
                        dp[i][1][0]%=mod;
                    }
                    else{
                        dp[i][0][2]+=dp[i-1][0][j];
                        dp[i][0][2]%=mod;
                    }
                }
                else{
                    if(j+2>=(1<<k)){
                        dp[i][1][0]+=dp[i-1][0][j];
                        dp[i][1][0]%=mod;
                    }
                    else{
                        dp[i][0][j+2]+=dp[i-1][0][j];
                        dp[i][0][j+2]%=mod;
                    }
                }

            }
            dp[i][1][0]+=dp[i-1][1][0];
            dp[i][1][0]%=mod;
        }
        else{
            for(int j=0;j<(1<<12);j++){
                if(j+1>=(1<<k)){
                    dp[i][1][0]+=dp[i-1][0][j];
                    dp[i][1][0]%=mod;
                }
                else{
                    dp[i][0][j+1]+=dp[i-1][0][j];
                    dp[i][0][j+1]%=mod;
                }
                
            }
            dp[i][1][0]+=dp[i-1][1][0];
            dp[i][1][0]%=mod;
            for(int j=0;j<(1<<12);j++){
                if(j&1){
                    if(2>=(1<<k)){
                        dp[i][1][0]+=dp[i-1][0][j];
                        dp[i][1][0]%=mod;
                    }
                    else{
                        dp[i][0][2]+=dp[i-1][0][j];
                        dp[i][0][2]%=mod;
                    }
                }
                else{
                    if(j+2>=(1<<k)){
                        dp[i][1][0]+=dp[i-1][0][j];
                        dp[i][1][0]%=mod;
                    }
                    else{
                        dp[i][0][j+2]+=dp[i-1][0][j];
                        dp[i][0][j+2]%=mod;
                    }
                }
            }
            dp[i][1][0]+=dp[i-1][1][0];
                dp[i][1][0]%=mod;
        }
    }
    
    std::cout<<dp[n][1][0]<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
