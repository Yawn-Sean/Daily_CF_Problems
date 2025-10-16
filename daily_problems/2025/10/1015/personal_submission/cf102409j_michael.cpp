#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n,sum;
    std::cin >> n >> sum;
    std::vector<ll> pre(n);
    for(int i = 1; i < n; ++i){
        std::cin >> pre[i];
    }
    pre.push_back(sum);
    int l = 1,r = 3;
    ll ans = LLONG_MAX;
    for(int mid = 2; mid < n; ++mid){
        while(l + 1 < mid && pre[mid] - pre[l + 1] > pre[l + 1]) l++;
        while(r + 1 < n && pre[n] - pre[r + 1] > pre[r + 1] - pre[mid]) r++;

        for(int i = l; i <= l + 1; ++i){
            for(int j = r; j <= r + 1; ++j){
                ll a = pre[i] - pre[0];
                ll b = pre[mid] - pre[i];
                ll c = pre[j] - pre[mid];
                ll d = pre[n] - pre[j];
                ans = std::min(ans,std::max({a,b,c,d})- std::min({a,b,c,d}));
            }
        }
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