#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m,s,e;
    std::cin>>n>>m>>s>>e;
    int maxn=s/e;
    if(maxn==0){
        std::cout<<0<<endl;
        return ;
    }
    std::vector<int> a(n+1);
    std::vector b(1e5+10,std::vector<int>());
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    int x;
    int ans=0;
    for(int j=1;j<=m;j++){
        std::cin>>x;
        b[x].push_back(j);
    }
    std::vector dp(maxn+1,std::vector<int>(n+1,1e9));
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=maxn;i++){
        int cur=1e9;
        for(int j=1;j<=n;j++){
        
            cur=std::min(dp[i-1][j-1],cur);
            auto p=std::upper_bound(b[a[j]].begin(),b[a[j]].end(),cur);
            if(p!=b[a[j]].end()){
                dp[i][j]=*p;
            }
        }
        for(int j=1;j<=n;j++){
            if(dp[i][j]!=1e9&&e*i+j+dp[i][j]<=s){
                ans=i;
                break;
            }
        }
    }
    std::cout<<ans<<endl;
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
