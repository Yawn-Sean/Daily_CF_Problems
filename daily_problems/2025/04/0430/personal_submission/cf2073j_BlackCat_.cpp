#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        a[x-1]=i;
    }
    std::vector dp(n,std::vector<int>(n,0));
    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            int k=j+i;
            dp[j][k]=1e9;
            for(int w=j;w<k;w++){
                dp[j][k]=std::min(dp[j][k],dp[j][w]+dp[w+1][k]+abs(a[j]-a[w+1]));
            }
        }
    }
    std::cout<<dp[0][n-1]<<endl;
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
