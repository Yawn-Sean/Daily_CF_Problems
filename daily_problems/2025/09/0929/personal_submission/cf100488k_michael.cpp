#include <bits/stdc++.h>
#define ll long long

void solve(){
    int n;
    std::cin >> n;
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
    ll ans = 0,total = 0;
    for(int i = 0; i < n; ++i){
        int x;
        std::cin >> x;

        if(pq.size() < (i / 2 + 1)){
            pq.push(x);
            ans += x;
        }else if(pq.top() < x){
            ans -= pq.top();
            pq.pop();
            pq.push(x);
            ans += x;
        }
        total += x;
    }
    std::cout << ans << ' ' << total - ans;
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