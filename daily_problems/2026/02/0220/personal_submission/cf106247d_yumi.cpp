#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = -1;
    auto check = [&](ll x) -> bool{
        return n + 1 <= x && x <= n + k;
    };
    for(ll i = 1;i * i <= n;i++){
        if(n % i == 0){
            ll p = (i) * (n / i + 1);
            if(check(p))    ans = max(ans, p);
            p = (n / i) * (i + 1);
            if(check(p))    ans = max(ans, p);
        }
    }
    cout << ans << "\n";
}

int main(){
    solve();
    return 0;
}