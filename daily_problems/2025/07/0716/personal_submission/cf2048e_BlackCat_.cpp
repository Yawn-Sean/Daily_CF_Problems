#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    if(2*n-1<m){
        std::cout<<"NO"<<endl;
        return ;
    }
    std::vector ans(2*n,std::vector<int>(m+1));
    for(int i=1;i<=n;i++){
        int s=2*(i-1);
        for(int j=0;j<m;j++){
            ans[s][j]=i;
            ans[(s+1)%(2*n)][j]=i;
            s+=1;
            s%=(2*n);
        }
    }
    std::cout<<"YES"<<endl;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++){
            std::cout<<ans[i][j]<<" \n"[j==m-1];
        }
    }
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
