#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n);
    d64 d;
    for(int i=0;i<n;i++){
        std::cin>>a[i]>>d;
        a[i]--;
    }
    std::vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        dp[a[i]]=dp[a[i]]+1;
        for(int j=0;j<a[i];j++){
            dp[a[i]]=std::max(dp[a[i]],dp[j]+1);
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        ans=std::max(ans,dp[i]);
    }
    std::cout<<n-ans<<endl;
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
