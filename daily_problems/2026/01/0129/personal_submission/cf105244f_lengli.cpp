/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1000000000;

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> b(n),c(n);
    for(auto &x:b) std::cin>>x;
    for(auto &x:c) std::cin>>x;
    std::vector<int> f(1010,inf);
    f[0]=f[1]=0;
    for(int i=0;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            int v=i+i/j;
            if(v<=1000) f[v]=std::min(f[v],f[i]+1);
        }
    } 

    k=std::min(k,13*1000);
    std::vector<int> dp(k+1,0);
    for(int i=0;i<n;i++){
        int x=f[b[i]];
        int v=c[i];
        for(int j=k;j>=x;j--){
            dp[j]=std::max(dp[j],dp[j-x]+v);
        }
    }
    std::cout<<dp[k]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
