#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solveC() {
    ll x, k;
    cin >> x >> k;
    if (x == 0) return cout << "0\n", void();
    ll v = qpow(2, k), v2 = v * 2 % mod;
    cout << (x % mod * v2 % mod + mod + 1 - v) % mod << '\n';
}

int main() {
    solveC();
    return 0;
}
