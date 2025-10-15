#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    i64 n,m,k;
    std::cin>>n>>m>>k;
    std::vector<i64> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    i64 l=a[0];
    for(int i=0;i<n;i+=2){
        l=std::min(l,a[i]);
    }
    i64 r=a[n-1];
    for(int i=n-1;i>=0;i-=2){
        r=std::min(r,a[i]);
    }
    if(n%2==0){
        std::cout<<0<<endl;
        return ;
    }
    i64 need=n/2+1;
    if(m<need){
        std::cout<<0<<endl;
        return ;

    }
    i64 ans=(m)/(need)*k;
    std::cout<<std::min(ans,std::max(l,r))<<endl;
    // 2 3 4 5
    // 1 4 3 6
    // 2 3 4 5 6
    // 1 4 3 6 5
    // 4 1 3
    // 3 2 2
    // 2 3 1
    // 2 4 0
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
