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
        std::cin>>a[i];
    }
    i64 ans;
    int w=0;
    int id=0;
    for(int i=1;i<n;i++){
        int cnt=a[i-1]-a[i]+1;
        if(cnt>=w){
            w=cnt;
            id=i;
        }
    }
    auto check=[&](i64 x){
        for(int i=0;i<a.size();i++) {
            if(std::__popcount(x+i)!=a[i])
                return false;
        }
        return true;
    };
    ans=-id+(1ll<<w)*((1ll<<a[id])-1);
    if(ans>=0&&check(ans)) {
        std::cout<<ans<<endl;
    } else {
        std::cout<<-1<<endl;
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
