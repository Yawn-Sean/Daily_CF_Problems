#include <bits/stdc++.h>
#define ll long long

std::vector<ll> all;
void init(){
    int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    all.push_back(1L);
    for(auto x:prime){
        int size = all.size();
        for(int i = 0; i < size; ++i){
            all.push_back(all[i] * x);
        }
    }
    std::sort(all.begin(),all.end());
}

void solve(){
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    ll ans = 0;
    for(auto x:all){
        bool flag = 1;
        for(int i = 0; i < n; ++i){
            if(std::gcd(x,a[i]) == 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans = x;
            break;
        }
    }
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    init();
    while(t--){
        solve();
    }
    std::cout << std::flush;
    return 0;
}