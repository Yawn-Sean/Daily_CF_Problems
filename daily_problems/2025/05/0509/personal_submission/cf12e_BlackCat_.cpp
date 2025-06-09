#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector ans(n,std::vector<int>(n,0));
    n--;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=(i+j)%n+1;
        }
    }
    for(int i=0;i<n;i++){
        ans[i][n]=ans[n][i]=ans[i][i];
        ans[i][i]=0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            std::cout<<ans[i][j]<<" \n"[j==n];
        }
    }
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
