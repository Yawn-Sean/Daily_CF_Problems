#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<i64> a(n);
    i64 sum=0;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        sum+=a[i];
    }
    i64 ans=0;
    i64 k=0;
    i64 need=sum/n;
    for(int i=0;i<n;i++){
        a[i]+=k;
        ans+=abs(a[i]-need);
        k=a[i]-need;
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
