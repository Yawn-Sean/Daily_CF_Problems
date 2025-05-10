#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    if(n==2){
        std::cout<<3<<endl;
        std::cout<<"2 1 2"<<endl;
        return ;
    }
    std::cout<<(n/2)*3+(n&1)<<endl;
    for(int i=2;i<=n;i+=2){
        std::cout<<i<<" ";
    }
    for(int i=1;i<=n;i+=2){
        std::cout<<i<<" ";
    }
    for(int i=2;i<=n;i+=2){
        std::cout<<i<<" ";
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
