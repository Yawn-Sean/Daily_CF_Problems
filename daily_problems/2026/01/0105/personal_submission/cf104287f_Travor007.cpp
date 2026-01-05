//20260105_cf104287f_Travor007.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vi;
const char nl = '\n';
const ll MOD = 1e9 + 7;
const int MX = 2e5 + 5;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll g1 = gcd(a, c);
    ll g2 = gcd(b, c);
    ll lcm_g = (g1 * g2) / gcd(g1, g2);

    cout << c - lcm_g << nl;
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
