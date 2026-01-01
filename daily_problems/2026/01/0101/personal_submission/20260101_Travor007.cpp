#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<ll> vl;
const char nl = '\n';

void solve() {
    ll x, k;
    cin >> x >> k;

    vl exps;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ll cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            exps.push_back(cnt);
        }
    }

    if (x > 1) exps.push_back(1);

    int ans = 0;
    for (int L = 0; L <= 60; L++) {
        ll need = 1LL << L, cost = 0;
        bool ok = true;
        for (ll e : exps) {
            ll rem = e % need;
            if (rem != 0) {
                cost += need - rem;
                if (cost > k) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) ans = L;
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
