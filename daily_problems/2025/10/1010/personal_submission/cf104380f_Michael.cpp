#include <bits/stdc++.h>
#define ll long long

void solve(){
    int n,l,r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for(auto &t :a){
        std::cin >> t;
    }
    int sz = std::max(l - 1,n - r) + (r - l + 1);
    std::sort(a.begin(),a.begin() + sz);
    ll ans = 0;
    for(int i = 0,index = sz - 1; i < r - l + 1; ++i,--index){
        ans += a[index];
    }
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int t;
    // std::cin >> t;
    // while(t--){
        solve();
    // }
    std::cout << std::flush;
    return 0;
}