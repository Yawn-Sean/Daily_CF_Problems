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
    std::vector<int> b(n);
    int v=0;
    std::map<i64,int> mp;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        mp[a[i]]++;
    }
    for(int i=0;i<n;i++){
        std::cin>>b[i];
        v+=(a[i]==b[i]);
        mp[b[i]]++;
    }
    i64 ans=1;
    i64 m=0;
    std::cin>>m;
    for(auto [x,y]:mp){
        i64 res=1;
        for(i64 i=1;i<=y;i++){
            res=res*i;
            if(v>0&&i%2==0){
                v--;
                res/=2;
            }
            res%=m;
        }
        ans*=res;
        ans%=m;
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
