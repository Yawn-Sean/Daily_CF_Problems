#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    i64 n;
    std::cin>>n;
    i64 now=2;
    std::cout<<2<<endl;

    for(i64 i=2;i<=n;i++){

        std::cout<<i*(i+1)*(i+1)-(i-1)<<endl;
        now=i;
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
