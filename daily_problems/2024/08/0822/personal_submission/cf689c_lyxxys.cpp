#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e7, mod = 1e9+7, inf = 1e9;
vector <int> prms;

void solve(){
    ll m;
    cin >> m;
    auto call = [&](ll x)->ll{
        ll res = 0;
        for (ll i = 2; i < x; ++ i){
            ll ys = i*i*i;
            if (ys > x) break;
            res += x/ys;
        }
        return res;
    };

    ll l = 1, r = 1e16;
    while (l < r){
        ll mid = l+r >> 1;
        if (call(mid) >= m) r = mid;
        else l = mid+1;
    }
    if (call(l) == m) cout << l << "\n";
    else cout << -1 << "\n";
}

