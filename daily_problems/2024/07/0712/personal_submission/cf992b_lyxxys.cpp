#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200050, mod = 1e9 + 7, inf = 1e9;

void solve(){
    function<ll(ll, ll)> gcd = [&](ll a, ll b){
        return !b ? a : gcd(b, a%b);
    };

    int l, r, x, y;
    cin >> l >> r >> x >> y;

    int d = gcd(x, y);
    x /= d, y /= d;

    vector<ll> prm;
    for (int i = 2; i <= y/i; ++ i){
        if (y%i == 0){
            ll ans = 1;
            while (y%i==0) y /= i, ans *= i;
            prm.push_back(ans);
        }
    }
    if (y > 1) prm.push_back(y);

    int n = (int)prm.size(), res = 0;
    if (y%x == 0) {
        for (int i = 0; i < 1 << n; ++i) {
            ll u1 = x, u2 = x;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) u1 *= prm[j];
                else u2 *= prm[j];
            }
            if (min(u1, u2) * d >= l && max(u1, u2) * d <= r) {
                ++ res;
            }
        }
    }
    cout << res << "\n";
}
