#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

void solve(){
    const ll inf = 1e18;

    ll n;
    cin >> n;
    vector <ll> ans;

    auto f = [&](ll x, int i)->ll{
        if (x-1 > 2*inf/x) return inf+1;
        ll res = x*(x-1)/2;
        if (res > n) return inf+1;
        while (i--){
            res += x;
            if (res > n) return inf+1;
            x *= 2;
        }
        return res;
    };
    auto call = [&](int i)->void{
        #define id(x) (2*x-1)
        ll l = 1, r = inf, bas = 1ll<<i;
        while (l < r){
            ll mid = l+r+1 >> 1;
            if (f(id(mid), i) <= n) l = mid;
            else r = mid-1;
        }
        if (f(id(l), i) == n) ans.push_back(bas*id(l));
    };

    for (int i = 0; i <= 60; ++ i) call(i);

    if (!ans.size()) cout << -1 << "\n";
    else {
        sort(ans.begin(), ans.end());
        for (auto &x : ans) cout << x << "\n";
    }
}
 
