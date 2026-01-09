//20260108_cf105390C2_Travor007.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;
const int MX = 3e5 + 12;
const char nl = '\n';

void solve() {
    static vector<ll> v;
    static bool init = false;

    if (!init) {
        init = true;
        int N = 300011;
        v.resize(N);
        v[1] = 1;
        v[2] = 2;

        ll val = 3, diff = 3;
        for (ll i = 3; i < N; i += 2) {
            v[i] = (v[i - 1] * (val % MOD)) % MOD;
            v[i + 1] = (v[i] * 2) % MOD;
            val += diff;
            diff++;
        }
    }
    
    ll n;
    cin >> n;
    cout << v[n] << nl;
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
